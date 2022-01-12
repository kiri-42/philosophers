/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:30:37 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/12 02:37:49 by tkirihar         ###   ########.fr       */
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

static void	set_log_message(t_log_message *log_message)
{
	log_message[TAKEAFORK].color = F_GREEN;
	log_message[EATING].color = F_YELLOW;
	log_message[SLEEPING].color = F_LIGHT_BLUE;
	log_message[THINKING].color = F_BLUE;
	log_message[DIED].color = F_RED;
	log_message[TAKEAFORK].message = TAKEAFORK_M;
	log_message[EATING].message = EATING_M;
	log_message[SLEEPING].message = SLEEPING_M;
	log_message[THINKING].message = THINKING_M;
	log_message[DIED].message = DIED_M;
}

static void	set_treads(t_management_data *mdata)
{
	mdata->philo_treads
		= (pthread_t *)malloc(sizeof(pthread_t) * mdata->opts.num_of_philos);
	if (mdata->philo_treads == NULL)
		finish_error("malloc");
}

static void	set_mutex(t_management_data *mdata)
{
	size_t	i;

	mdata->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
						(mdata->opts.num_of_philos + 1));
	if (mdata->philo_treads == NULL)
	{
		free(&mdata->philo_treads);
		finish_error("malloc");
	}
	i = 0;
	while (i <= (size_t)mdata->opts.num_of_philos)
	{
		pthread_mutex_init(&mdata->fork_mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&mdata->philo_id_mutex, NULL);
	pthread_mutex_init(&mdata->put_log_mutex, NULL);
}

void	set_mdata(int ac, char **av, t_management_data *mdata)
{
	set_opts(ac, av, &mdata->opts);
	set_log_message(mdata->log_message);
	set_treads(mdata);
	set_mutex(mdata);
	mdata->philo_id = 1;
}
