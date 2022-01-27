/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:27:18 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/27 23:37:38 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*death_monitor(void *arg)
{
	t_action_data	*ad;
	struct timeval	now;
	long long		now_ms;

	ad = (t_action_data *)arg;
	while (1)
	{
		gettimeofday(&now, NULL);
		now_ms = get_ms(&now);
		if (now_ms - ad->philo.time_ate > \
			ad->opts->time_to_die && !ad->philos->is_death)
		{
			ad->philo.time = now;
			ad->philos->is_death = true;
			put_log(ad, DIED);
			// ad->philo.is_death = DEATH;
			// pthread_mutex_lock(&ad->mutex->death_info_mutex);
			// ad->philos->is_death = true;
			// ad->philos->death_time = now_ms;
			// pthread_mutex_unlock(&ad->mutex->death_info_mutex);
		}
		usleep(200);
	}
	return (NULL);
}
