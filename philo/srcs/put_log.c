/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_log.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:34:46 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/27 23:51:09 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	put_log(t_action_data *ad, int log_num)
{
	long long	time_ms;

	if ((ad->philos->is_death || *ad->is_finish_eating || *ad->is_error) \
		&& log_num != DIED)
		return ;
	time_ms = get_ms(&ad->philo.time);
	pthread_mutex_lock(&ad->mutex->put_log_mutex);
	printf("%s", ad->log_message[log_num].color);
	printf("%lld %d %s\n", time_ms, \
			ad->philo.philo_id + 1, \
			ad->log_message[log_num].message);
	printf("%s", F_RESET);
	pthread_mutex_unlock(&ad->mutex->put_log_mutex);
}
