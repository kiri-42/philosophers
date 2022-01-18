/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:21:53 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/18 17:09:25 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	create_monitor_treads(t_action_data *adata)
{
	int	philo_id;

	philo_id = adata->philo.philo_id;
	if (pthread_create(&adata->thread->philo_treads[philo_id], \
						NULL, death_monitor, adata) != 0)
	{
		free_adata(adata);
		finish_error(THREAD_CREATE_ERROR);
	}
}

static void	eat_action(t_action_data *adata)
{
	int	fork1;
	int	fork2;

	fork1 = adata->philo.philo_id;
	if (fork1 + 1 != adata->opts->num_of_philos)
		fork2 = fork1 + 1;
	else
		fork2 = 0;
	pthread_mutex_lock(&adata->mutex->fork_mutex[fork1]);
	gettimeofday(&adata->philo.time, NULL);
	put_log(adata, TAKEAFORK);
	pthread_mutex_lock(&adata->mutex->fork_mutex[fork2]);
	gettimeofday(&adata->philo.time, NULL);
	put_log(adata, TAKEAFORK);
	gettimeofday(&adata->philo.time, NULL);
	put_log(adata, EATING);
	adata->philo.time_ate = get_ms(&adata->philo.time);
	usleep(adata->opts->time_to_eat * 1000);
	pthread_mutex_unlock(&adata->mutex->fork_mutex[fork1]);
	pthread_mutex_unlock(&adata->mutex->fork_mutex[fork2]);
	adata->philos->eat_cnt[adata->philo.philo_id]++;
}

static void	sleep_action(t_action_data *adata)
{
	gettimeofday(&adata->philo.time, NULL);
	put_log(adata, SLEEPING);
	usleep(adata->opts->time_to_sleep * 1000);
}

static void	think_action(t_action_data *adata)
{
	gettimeofday(&adata->philo.time, NULL);
	put_log(adata, THINKING);
}

static void	set_adata(t_management_data *mdata, t_action_data *adata)
{
	adata->opts = &mdata->opts;
	adata->thread = &mdata->thread;
	adata->mutex = &mdata->mutex;
	adata->philos = &mdata->philos;
	adata->log_message = mdata->log_message;
	pthread_mutex_lock(&adata->mutex->philo_id_mutex);
	adata->philo.philo_id = adata->philos->philo_id++;
	pthread_mutex_unlock(&adata->mutex->philo_id_mutex);
	adata->philo.is_death = LIFE;
	adata->philos->eat_cnt[adata->philo.philo_id] = 0;
	if (adata->philo.philo_id % 2 == 1)
		usleep(200);
	gettimeofday(&adata->philo.time, NULL);
	adata->philo.time_ate = get_ms(&adata->philo.time);
}

void	*philo_action(void *arg)
{
	t_management_data	*mdata;
	t_action_data		adata;

	mdata = (t_management_data *)arg;
	set_adata(mdata, &adata);
	create_monitor_treads(&adata);
	while (1)
	{
		eat_action(&adata);
		sleep_action(&adata);
		think_action(&adata);
	}
	return (NULL);
}
