/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_global_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:30:37 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/13 17:12:02 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	set_opts(int ac, char **av)
{
	g_opts.num_of_philos = ft_atoi(av[1]);
	g_opts.time_to_die = ft_atoi(av[2]);
	g_opts.time_to_eat = ft_atoi(av[3]);
	g_opts.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		g_opts.num_of_must_eat = ft_atoi(av[5]);
	else
		g_opts.num_of_must_eat = -1;
}

static void	set_treads(void)
{
	g_tread_data.philo_treads
		= (pthread_t *)malloc(sizeof(pthread_t) * g_opts.num_of_philos);
	if (g_tread_data.philo_treads == NULL)
		finish_error(MALLOC_ERROR);
	g_tread_data.monitor_treads
		= (pthread_t *)malloc(sizeof(pthread_t) * g_opts.num_of_philos);
	if (g_tread_data.monitor_treads == NULL)
	{
		free(g_tread_data.philo_treads);
		finish_error(MALLOC_ERROR);
	}
}

static void	set_mutex(void)
{
	size_t	i;

	g_mutex_data.fork_mutex
		= (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
									(g_opts.num_of_philos + 1));
	if (g_mutex_data.fork_mutex == NULL)
	{
		free(g_tread_data.philo_treads);
		free(g_tread_data.monitor_treads);
		finish_error(MALLOC_ERROR);
	}
	i = 0;
	while (i <= (size_t)g_opts.num_of_philos)
	{
		pthread_mutex_init(&g_mutex_data.fork_mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&g_mutex_data.philo_id_mutex, NULL);
	pthread_mutex_init(&g_mutex_data.put_log_mutex, NULL);
	pthread_mutex_init(&g_mutex_data.death_info_mutex, NULL);
}

static void	set_philos(void)
{
	g_philos_data.philo_id = 1;
	g_philos_data.death_flag = 0;
	g_philos_data.eat_cnt
		= (int *)malloc(sizeof(int) * g_opts.num_of_philos);
	if (g_philos_data.eat_cnt == NULL)
	{
		free(g_tread_data.philo_treads);
		free(g_tread_data.monitor_treads);
		free(g_mutex_data.fork_mutex);
		finish_error(MALLOC_ERROR);
	}
}

void	set_global_data(int ac, char **av)
{
	set_opts(ac, av);
	set_treads();
	set_mutex();
	set_philos();
	set_log_message();
}
