/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:08:25 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/18 23:51:02 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	finish_died(t_management_data *mdata, int philo_id)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	printf("%s", mdata->log_message[DIED].color);
	printf("%lld %d %s\n", get_ms(&time), philo_id, DIED_M);
	printf("%s", F_RESET);
	return (SUCCESS);
}

static int	create_main_monitor_thread(t_management_data *mdata)
{
	if (pthread_create(&mdata->thread.main_monitor_tread, NULL, \
		main_monitor, mdata) != 0)
	{
		free_mdata(mdata);
		return (finish_error(THREAD_CREATE_ERROR));
	}
	return (SUCCESS);
}

static int	create_philo_threads(t_management_data *mdata)
{
	int	i;

	i = 0;
	while (i < mdata->opts.num_of_philos)
	{
		if (pthread_create(&mdata->thread.philo_treads[i], NULL, \
			philo_action, mdata) != 0)
		{
			free_mdata(mdata);
			return (finish_error(THREAD_CREATE_ERROR));
		}
		i++;
	}
	return (SUCCESS);
}

int	run_simulation(t_management_data *mdata)
{
	if (mdata->opts.num_of_philos == 1)
	{
		free_mdata(mdata);
		return (finish_died(mdata, 1));
	}
	if (!(create_main_monitor_thread(mdata) == SUCCESS && \
		create_philo_threads(mdata) == SUCCESS))
		return (ERROR);
	pthread_join(mdata->thread.main_monitor_tread, NULL);
	free_mdata(mdata);
	return (SUCCESS);
}
