/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:30:37 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/13 14:33:06 by tkirihar         ###   ########.fr       */
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

static void	set_log_message(void)
{
	g_log_message[TAKEAFORK].color = F_GREEN;
	g_log_message[EATING].color = F_YELLOW;
	g_log_message[SLEEPING].color = F_LIGHT_BLUE;
	g_log_message[THINKING].color = F_BLUE;
	g_log_message[DIED].color = F_RED;
	g_log_message[TAKEAFORK].message = TAKEAFORK_M;
	g_log_message[EATING].message = EATING_M;
	g_log_message[SLEEPING].message = SLEEPING_M;
	g_log_message[THINKING].message = THINKING_M;
	g_log_message[DIED].message = DIED_M;
}

static void	set_treads(void)
{
	g_tread_data.philo_treads
		= (pthread_t *)malloc(sizeof(pthread_t) * g_opts.num_of_philos);
	if (g_tread_data.philo_treads == NULL)
		finish_error("malloc");
	g_tread_data.monitor_treads
		= (pthread_t *)malloc(sizeof(pthread_t) * g_opts.num_of_philos);
	if (g_tread_data.monitor_treads == NULL)
	{
		// free
		finish_error("malloc");
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
		// free
		finish_error("malloc");
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

void	set_mdata(int ac, char **av)
{
	set_opts(ac, av);
	set_log_message();
	set_treads();
	set_mutex();
	g_philos_data.philo_id = 1;
	g_philos_data.death_flag = 0;
	g_philos_data.eat_cnt
		= (int *)malloc(sizeof(int) * g_opts.num_of_philos);
	if (g_philos_data.eat_cnt == NULL)
	{
		// free
		finish_error("malloc");
	}
}
