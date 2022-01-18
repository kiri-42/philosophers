/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_log.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:34:46 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/18 06:16:05 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	put_log(t_action_data *action_data, int log_num)
{
	long long	time_ms;

	time_ms = get_ms(&action_data->philo.time);
	pthread_mutex_lock(&action_data->mutex->put_log_mutex);
	printf("%s", action_data->log_message[log_num].color);
	printf("%lld %d %s\n", time_ms, \
			action_data->philo.philo_id + 1, \
			action_data->log_message[log_num].message);
	printf("%s", F_RESET);
	pthread_mutex_unlock(&action_data->mutex->put_log_mutex);
}
