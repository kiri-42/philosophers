/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_action_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:52:46 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/27 23:42:53 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_action_data(t_management_data *md, t_action_data *ad)
{
	ad->opts = &md->opts;
	ad->thread = &md->thread;
	ad->mutex = &md->mutex;
	ad->philos = &md->philos;
	ad->log_message = md->log_message;
	ad->is_error = &md->is_error;
	ad->is_finish_eating = &md->is_finish_eating;
	pthread_mutex_lock(&ad->mutex->philo_id_mutex);
	ad->philo.philo_id = ad->philos->philo_id++;
	pthread_mutex_unlock(&ad->mutex->philo_id_mutex);
	ad->philos->eat_cnt[ad->philo.philo_id] = 0;
	if (ad->philo.philo_id % 2 == 1)
		usleep(200);
	gettimeofday(&ad->philo.time, NULL);
	ad->philo.time_ate = get_ms(&ad->philo.time);
}
