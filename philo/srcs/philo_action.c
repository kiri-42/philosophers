/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:21:53 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/13 01:46:28 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	create_monitor_treads(t_philo_data *philo)
{
	if (pthread_create(&g_tread_data.monitor_treads[philo->philo_id - 1], NULL, \
						death_monitor, philo) != 0)
	{
		// free
		exit(1);
	}
}

static void	eat_action(t_philo_data *philo)
{
	int	fork1;
	int	fork2;

	fork1 = philo->philo_id;
	if (philo->philo_id != g_opts.num_of_philos)
		fork2 = philo->philo_id + 1;
	else
		fork2 = 1;
	pthread_mutex_lock(&g_mutex_data.fork_mutex[fork1]);
	gettimeofday(&philo->time, NULL);
	put_log(philo, TAKEAFORK);
	pthread_mutex_lock(&g_mutex_data.fork_mutex[fork2]);
	gettimeofday(&philo->time, NULL);
	put_log(philo, TAKEAFORK);
	gettimeofday(&philo->time, NULL);
	put_log(philo, EATING);
	philo->time_ate = get_ms(&philo->time);
	usleep(g_opts.time_to_eat * 1000);
	pthread_mutex_unlock(&g_mutex_data.fork_mutex[fork1]);
	pthread_mutex_unlock(&g_mutex_data.fork_mutex[fork2]);
}

static void	sleep_action(t_philo_data *philo)
{
	gettimeofday(&philo->time, NULL);
	put_log(philo, SLEEPING);
	usleep(g_opts.time_to_sleep * 1000);
}

static void	think_action(t_philo_data *philo)
{
	gettimeofday(&philo->time, NULL);
	put_log(philo, THINKING);
}

void	*philo_action(void *arg)
{
	t_philo_data	philo;

	pthread_mutex_lock(&g_mutex_data.philo_id_mutex);
	philo.philo_id = g_philos_data.philo_id++;
	pthread_mutex_unlock(&g_mutex_data.philo_id_mutex);
	if (philo.philo_id % 2 == 0)
		usleep(200);
	gettimeofday(&philo.time, NULL);
	philo.time_ate = get_ms(&philo.time);
	create_monitor_treads(&philo);
	while (1)
	{
		eat_action(&philo);
		sleep_action(&philo);
		think_action(&philo);
	}
	return (arg);
}
