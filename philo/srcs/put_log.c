/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_log.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:34:46 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/12 00:35:07 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	put_log(pthread_mutex_t *put_log_mutex, struct timeval *time, \
				int philo_id, t_log_message *log_message)
{
	pthread_mutex_lock(put_log_mutex);
	printf("%s", log_message->color);
	printf("%lld %d %s\n", get_ms(time), philo_id, log_message->message);
	printf("%s", F_RESET);
	pthread_mutex_unlock(put_log_mutex);
}
