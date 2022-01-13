/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:08:25 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/13 14:39:19 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	create_main_monitor_tread(void)
{
	if (pthread_create(&g_tread_data.main_monitor_tread, NULL, \
		main_monitor, NULL) != 0)
	{
		exit(1);
	}
}

static void	create_philo_treads(void)
{
	size_t	i;

	i = 0;
	while (i < (size_t)g_opts.num_of_philos)
	{
		if (pthread_create(&g_tread_data.philo_treads[i], NULL, \
			philo_action, NULL) != 0)
		{
			exit(1);
		}
		i++;
	}
}

void	run_simulation(void)
{
	if (g_opts.num_of_philos == 1)
		finish_died(1);
	create_main_monitor_tread();
	create_philo_treads();
	pthread_join(g_tread_data.main_monitor_tread, NULL);
	printf("finish\n");
}
