/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:30:37 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/11 16:26:59 by tkirihar         ###   ########.fr       */
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

void	set_mdata(int ac, char **av, t_management_data *mdata)
{
	set_opts(ac, av, &mdata->opts);
	mdata->philo_treads
		= (pthread_t *)malloc(sizeof(pthread_t) * mdata->opts.num_of_philos);
	if (mdata->philo_treads == NULL)
		finish_error("malloc");
	mdata->fork_mutex
		= (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
			(mdata->opts.num_of_philos + 1));
	if (mdata->philo_treads == NULL)
	{
		free(&mdata->philo_treads);
		finish_error("malloc");
	}
	mdata->philo_id = 1;
	pthread_mutex_init(&mdata->philo_id_mutex, NULL);
}
