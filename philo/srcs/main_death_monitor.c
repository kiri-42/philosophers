/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_death_monitor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:24:15 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/13 14:38:47 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	check_eat_cnt(void)
{
	size_t	i;

	if (g_opts.num_of_must_eat == -1)
		return (false);
	i = 0;
	while (i < (size_t)g_opts.num_of_philos)
	{
		if (g_philos_data.eat_cnt[i] < g_opts.num_of_must_eat)
			return (false);
		i++;
	}
	return (true);
}

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

void	*main_monitor(void *arg)
{
	while (1)
	{
		if (g_philos_data.death_flag != LIFE || check_eat_cnt())
		{
			detach_all_treads();
			break ;
		}
		usleep(200);
	}
	return (arg);
}
