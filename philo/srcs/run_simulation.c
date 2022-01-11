/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:08:25 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/11 17:01:26 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	*philo_action(void *arg)
{
	int					philo_id;
	struct timeval		time;
	t_management_data	*mdata;

	mdata = (t_management_data *)arg;
	pthread_mutex_lock(&mdata->philo_id_mutex);
	philo_id = mdata->philo_id++;
	pthread_mutex_unlock(&mdata->philo_id_mutex);
	if (philo_id % 2 == 1)
		usleep(200);
	while (1)
	{
		eat_action(mdata, philo_id, &time);
		sleep_action(mdata, philo_id, &time);
		think_action(philo_id, &time);
	}
	return (NULL);
}

void	run_simulation(t_management_data *mdata)
{
	size_t	i;

	printf("%s %d\n", __FILE__, __LINE__);
	if (mdata->opts.num_of_philos == 1)
		finish_died(1);
	i = 0;
	while (i < (size_t)mdata->opts.num_of_philos)
	{
		if (pthread_create(&mdata->philo_treads[i], NULL, philo_action, mdata) != 0)
		{
			exit(1);
		}
		i++;
	}
}
