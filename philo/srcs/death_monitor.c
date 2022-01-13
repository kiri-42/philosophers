/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:27:18 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/13 14:24:09 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*death_monitor(void *arg)
{
	t_philo_data	*philo;
	struct timeval	now;
	long long		now_ms;

	philo = (t_philo_data *)arg;
	while (1)
	{
		gettimeofday(&now, NULL);
		now_ms = get_ms(&now);
		if (now_ms - philo->time_ate > g_opts.time_to_die)
		{
			pthread_mutex_lock(&g_mutex_data.death_info_mutex);
			g_philos_data.death_flag = philo->philo_id;
			g_philos_data.death_time = now_ms;
			pthread_mutex_unlock(&g_mutex_data.death_info_mutex);
			printf("died\n");
		}
		usleep(200);
	}
	return (arg);
}
