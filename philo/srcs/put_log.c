/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_log.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:34:46 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/12 22:41:32 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	put_log(t_philo_data *philo, int log_num)
{
	pthread_mutex_lock(&g_mutex_data.put_log_mutex);
	printf("%s", g_log_message[log_num].color);
	printf("%lld %d %s\n", get_ms(&philo->time), philo->philo_id, \
			g_log_message[log_num].message);
	printf("%s", F_RESET);
	pthread_mutex_unlock(&g_mutex_data.put_log_mutex);
}
