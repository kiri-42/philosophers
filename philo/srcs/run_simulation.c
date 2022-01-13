/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:08:25 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/13 23:47:07 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	finish_died(int philo_id)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	printf("%s", g_log_message[DIED].color);
	printf("%lld %d %s\n", get_ms(&time), philo_id, DIED_M);
	printf("%s", F_RESET);
	exit(0);
}

static void	create_main_monitor_tread(void)
{
	if (pthread_create(&g_tread_data.main_monitor_tread, NULL, \
		main_monitor, NULL) != 0)
	{
		free_all();
		finish_error(THREAD_CREATE_ERROR);
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
			free_all();
			finish_error(THREAD_CREATE_ERROR);
		}
		i++;
	}
}

void	run_simulation(void)
{
	if (g_opts.num_of_philos == 1)
	{
		free_all();
		finish_died(1);
	}
	create_main_monitor_tread();
	create_philo_treads();
	pthread_join(g_tread_data.main_monitor_tread, NULL);
}
