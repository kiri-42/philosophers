/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:30:37 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/18 01:40:49 by tkirihar         ###   ########.fr       */
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

static void	set_treads(t_management_data *mdata)
{
	mdata->thread.philo_treads
		= (pthread_t *)malloc(sizeof(pthread_t) * mdata->opts.num_of_philos);
	if (mdata->thread.philo_treads == NULL)
		finish_error(MALLOC_ERROR);
	mdata->thread.monitor_treads
		= (pthread_t *)malloc(sizeof(pthread_t) * mdata->opts.num_of_philos);
	if (mdata->thread.monitor_treads == NULL)
	{
		free(mdata->thread.philo_treads);
		finish_error(MALLOC_ERROR);
	}
}

static void	set_mutex(t_management_data *mdata)
{
	int	i;

	mdata->mutex.fork_mutex
		= (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
									mdata->opts.num_of_philos);
	if (mdata->mutex.fork_mutex == NULL)
	{
		free(mdata->thread.philo_treads);
		free(mdata->thread.monitor_treads);
		finish_error(MALLOC_ERROR);
	}
	i = 0;
	while (i <= mdata->opts.num_of_philos)
	{
		pthread_mutex_init(&mdata->mutex.fork_mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&mdata->mutex.philo_id_mutex, NULL);
	pthread_mutex_init(&mdata->mutex.put_log_mutex, NULL);
	pthread_mutex_init(&mdata->mutex.death_info_mutex, NULL);
}

// static void	set_philo(t_management_data *mdata)
// {
// 	mdata->philo
// 		= (t_philo_data *)malloc(sizeof(t_philo_data) * \
// 								mdata->opts.num_of_philos);
// 	if (mdata->philo == NULL)
// 	{
// 		free(mdata->thread.philo_treads);
// 		free(mdata->thread.monitor_treads);
// 		free(mdata->mutex.fork_mutex);
// 		finish_error(MALLOC_ERROR);
// 	}
// }

static void	set_philos(t_management_data *mdata)
{
	mdata->philos.philo_id = 0;
	mdata->philos.death_flag = 0;
	mdata->philos.eat_cnt
		= (int *)malloc(sizeof(int) * mdata->opts.num_of_philos);
	if (mdata->philos.eat_cnt == NULL)
	{
		free(mdata->thread.philo_treads);
		free(mdata->thread.monitor_treads);
		free(mdata->mutex.fork_mutex);
		// free(mdata->philo);
		finish_error(MALLOC_ERROR);
	}
}

void	set_mdata(int ac, char **av, t_management_data *mdata)
{
	set_opts(ac, av, &mdata->opts);
	set_treads(mdata);
	set_mutex(mdata);
	// set_philo(mdata);
	set_philos(mdata);
	set_log_message(mdata);
}
