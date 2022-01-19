/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:30:37 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/19 00:23:19 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	set_opts(int ac, char **av, t_options *opts)
{
	opts->num_of_philos = ft_atoi(av[1]);
	opts->time_to_die = ft_atoi(av[2]);
	opts->time_to_eat = ft_atoi(av[3]);
	opts->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		opts->num_of_must_eat = ft_atoi(av[5]);
	else
		opts->num_of_must_eat = -1;
}

static int	set_treads(t_management_data *md)
{
	md->thread.philo_treads
		= (pthread_t *)malloc(sizeof(pthread_t) * md->opts.num_of_philos);
	if (md->thread.philo_treads == NULL)
		finish_error(MALLOC_ERROR);
	md->thread.monitor_treads
		= (pthread_t *)malloc(sizeof(pthread_t) * md->opts.num_of_philos);
	if (md->thread.monitor_treads == NULL)
	{
		free(md->thread.philo_treads);
		return (finish_error(MALLOC_ERROR));
	}
	return (SUCCESS);
}

static int	set_mutex(t_management_data *md)
{
	int	i;

	md->mutex.fork_mutex
		= (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
									md->opts.num_of_philos);
	if (md->mutex.fork_mutex == NULL)
	{
		free(md->thread.philo_treads);
		free(md->thread.monitor_treads);
		return (finish_error(MALLOC_ERROR));
	}
	i = 0;
	while (i <= md->opts.num_of_philos)
	{
		pthread_mutex_init(&md->mutex.fork_mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&md->mutex.philo_id_mutex, NULL);
	pthread_mutex_init(&md->mutex.put_log_mutex, NULL);
	pthread_mutex_init(&md->mutex.death_info_mutex, NULL);
	return (SUCCESS);
}

static int	set_philos(t_management_data *md)
{
	md->philos.philo_id = 0;
	md->philos.death_flag = 0;
	md->philos.eat_cnt
		= (int *)malloc(sizeof(int) * md->opts.num_of_philos);
	if (md->philos.eat_cnt == NULL)
	{
		free(md->thread.philo_treads);
		free(md->thread.monitor_treads);
		free(md->mutex.fork_mutex);
		return (finish_error(MALLOC_ERROR));
	}
	return (SUCCESS);
}

int	set_mdata(int ac, char **av, t_management_data *md)
{
	set_opts(ac, av, &md->opts);
	if (!(set_treads(md) == SUCCESS && \
		set_mutex(md) == SUCCESS && \
		set_philos(md) == SUCCESS))
		return (ERROR);
	set_log_message(md);
	return (SUCCESS);
}
