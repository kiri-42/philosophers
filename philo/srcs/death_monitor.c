/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:27:18 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/18 17:13:07 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*death_monitor(void *arg)
{
	t_action_data	*adata;
	struct timeval	now;
	long long		now_ms;

	adata = (t_action_data *)arg;
	while (1)
	{
		gettimeofday(&now, NULL);
		now_ms = get_ms(&now);
		if (now_ms - adata->philo.time_ate > \
			adata->opts->time_to_die && !adata->philo.is_death)
		{
			adata->philo.time = now;
			put_log(adata, DIED);
			adata->philo.is_death = DEATH;
			pthread_mutex_lock(&adata->mutex->death_info_mutex);
			adata->philos->death_flag = adata->philo.philo_id;
			adata->philos->death_time = now_ms;
			pthread_mutex_unlock(&adata->mutex->death_info_mutex);
		}
		usleep(200);
	}
	return (NULL);
}
