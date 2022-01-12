/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_death_monitor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:24:15 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/13 01:24:47 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	detach_all_treads(void)
{
	size_t	i;

	i = 0;
	while (i < (size_t)g_opts.num_of_philos)
	{
		pthread_detach(g_tread_data.monitor_treads[i]);
		pthread_detach(g_tread_data.philo_treads[i]);
		i++;
	}
}

void	*main_death_monitor(void *arg)
{
	while (1)
	{
		if (g_philos_data.death_flag != LIFE)
		{
			detach_all_treads();
			break ;
		}
		usleep(200);
	}
	return (arg);
}
