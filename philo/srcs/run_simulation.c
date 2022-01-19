/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:08:25 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/19 00:24:45 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	finish_died(t_management_data *md, int philo_id)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	printf("%s", md->log_message[DIED].color);
	printf("%lld %d %s\n", get_ms(&time), philo_id, DIED_M);
	printf("%s", F_RESET);
	return (SUCCESS);
}

static int	create_main_monitor_thread(t_management_data *md)
{
	if (pthread_create(&md->thread.main_monitor_tread, NULL, \
		main_monitor, md) != 0)
	{
		free_mdata(md);
		return (finish_error(THREAD_CREATE_ERROR));
	}
	return (SUCCESS);
}

static int	create_philo_threads(t_management_data *md)
{
	int	i;

	i = 0;
	while (i < md->opts.num_of_philos)
	{
		if (pthread_create(&md->thread.philo_treads[i], NULL, \
			philo_action, md) != 0)
		{
			free_mdata(md);
			return (finish_error(THREAD_CREATE_ERROR));
		}
		i++;
	}
	return (SUCCESS);
}

int	run_simulation(t_management_data *md)
{
	if (md->opts.num_of_philos == 1)
	{
		free_mdata(md);
		return (finish_died(md, 1));
	}
	if (!(create_main_monitor_thread(md) == SUCCESS && \
		create_philo_threads(md) == SUCCESS))
		return (ERROR);
	pthread_join(md->thread.main_monitor_tread, NULL);
	free_mdata(md);
	return (SUCCESS);
}
