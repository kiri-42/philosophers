/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:56:57 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/11 16:03:51 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eat_action(t_management_data *mdata, int philo_id, struct timeval *time)
{
	int	fork1;
	int	fork2;

	fork1 = philo_id;
	if (philo_id != mdata->opts.num_of_philos)
		fork2 = philo_id + 1;
	else
		fork2 = 1;
	pthread_mutex_lock(&mdata->fork_mutex[fork1]);
	gettimeofday(time, NULL);
	put_log(time, philo_id, TAKEAFORK);
	pthread_mutex_lock(&mdata->fork_mutex[fork2]);
	gettimeofday(time, NULL);
	put_log(time, philo_id, TAKEAFORK);
	gettimeofday(time, NULL);
	put_log(time, philo_id, EATING);
	usleep(mdata->opts.time_to_eat);
	pthread_mutex_unlock(&mdata->fork_mutex[fork1]);
	pthread_mutex_unlock(&mdata->fork_mutex[fork2]);
}

void	sleep_action(t_management_data *mdata, int philo_id, \
						struct timeval *time)
{
	gettimeofday(time, NULL);
	put_log(time, philo_id, SLEEPING);
	usleep(mdata->opts.time_to_sleep);
}

void	think_action(int philo_id, struct timeval *time)
{
	gettimeofday(time, NULL);
	put_log(time, philo_id, SLEEPING);
}
