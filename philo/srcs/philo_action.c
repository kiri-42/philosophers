/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:21:53 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/27 23:42:46 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	create_monitor_treads(t_action_data *ad)
{
	int	philo_id;

	philo_id = ad->philo.philo_id;
	if (pthread_create(&ad->thread->philo_treads[philo_id], \
						NULL, death_monitor, ad) != 0)
	{
		*ad->is_error = ERROR;
		pthread_mutex_lock(&ad->mutex->put_log_mutex);
		finish_error(THREAD_CREATE_ERROR);
		pthread_mutex_unlock(&ad->mutex->put_log_mutex);
	}
}

static void	eat_action(t_action_data *ad)
{
	int	fork1;
	int	fork2;

	fork1 = ad->philo.philo_id;
	if (fork1 + 1 != ad->opts->num_of_philos)
		fork2 = fork1 + 1;
	else
		fork2 = 0;
	pthread_mutex_lock(&ad->mutex->fork_mutex[fork1]);
	gettimeofday(&ad->philo.time, NULL);
	put_log(ad, TAKEAFORK);
	pthread_mutex_lock(&ad->mutex->fork_mutex[fork2]);
	gettimeofday(&ad->philo.time, NULL);
	put_log(ad, TAKEAFORK);
	gettimeofday(&ad->philo.time, NULL);
	put_log(ad, EATING);
	ad->philo.time_ate = get_ms(&ad->philo.time);
	msleep(ad->opts->time_to_eat);
	pthread_mutex_unlock(&ad->mutex->fork_mutex[fork1]);
	pthread_mutex_unlock(&ad->mutex->fork_mutex[fork2]);
	ad->philos->eat_cnt[ad->philo.philo_id]++;
}

static void	sleep_action(t_action_data *ad)
{
	gettimeofday(&ad->philo.time, NULL);
	put_log(ad, SLEEPING);
	msleep(ad->opts->time_to_sleep);
}

static void	think_action(t_action_data *ad)
{
	gettimeofday(&ad->philo.time, NULL);
	put_log(ad, THINKING);
}

void	*philo_action(void *arg)
{
	t_management_data	*md;
	t_action_data		ad;

	md = (t_management_data *)arg;
	set_action_data(md, &ad);
	create_monitor_treads(&ad);
	while (1)
	{
		eat_action(&ad);
		sleep_action(&ad);
		think_action(&ad);
	}
	return (NULL);
}
