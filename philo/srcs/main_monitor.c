/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:24:15 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/19 16:37:16 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	check_eat_cnt(t_management_data *md)
{
	int	i;

	if (md->opts.num_of_must_eat == -1)
		return (false);
	i = 0;
	while (i < md->opts.num_of_philos)
	{
		if (md->philos.eat_cnt[i] < md->opts.num_of_must_eat)
			return (false);
		i++;
	}
	return (true);
}

static void	detach_all_treads(t_management_data *md)
{
	int	i;

	i = 0;
	while (i < md->opts.num_of_philos)
	{
		pthread_detach(md->thread.monitor_treads[i]);
		pthread_detach(md->thread.philo_treads[i]);
		i++;
	}
}

void	*main_monitor(void *arg)
{
	t_management_data	*md;

	md = arg;
	while (1)
	{
		if (md->philos.death_flag != LIFE || md->is_error || check_eat_cnt(md))
		{
			detach_all_treads(md);
			break ;
		}
		usleep(200);
	}
	return (NULL);
}
