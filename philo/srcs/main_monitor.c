/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:24:15 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/28 00:33:19 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	is_finish_eating(t_management_data *md)
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
		md->is_finish_eating = is_finish_eating(md);
		if (md->philos.is_death || md->is_error || md->is_finish_eating)
		{
			detach_all_treads(md);
			break ;
		}
		usleep(200);
	}
	return (NULL);
}
