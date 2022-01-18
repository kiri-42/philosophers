/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_death_monitor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:24:15 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/18 06:02:00 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	check_eat_cnt(t_management_data *mdata)
{
	int	i;

	if (mdata->opts.num_of_must_eat == -1)
		return (false);
	i = 0;
	while (i < mdata->opts.num_of_philos)
	{
		if (mdata->philos.eat_cnt[i] < mdata->opts.num_of_must_eat)
			return (false);
		i++;
	}
	return (true);
}

static void	detach_all_treads(t_management_data *mdata)
{
	int	i;

	i = 0;
	while (i < mdata->opts.num_of_philos)
	{
		pthread_detach(mdata->thread.monitor_treads[i]);
		pthread_detach(mdata->thread.philo_treads[i]);
		i++;
	}
}

void	*main_monitor(void *arg)
{
	t_management_data	*mdata;

	mdata = arg;
	while (1)
	{
		if (mdata->philos.death_flag != LIFE || check_eat_cnt(mdata))
		{
			detach_all_treads(mdata);
			break ;
		}
		usleep(200);
	}
	return (NULL);
}
