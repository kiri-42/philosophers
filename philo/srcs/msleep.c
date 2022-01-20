/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:14:00 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/20 18:51:01 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	msleep(long long sleep_time)
{
	struct timeval	time;
	long long		start_ms;
	long long		now_ms;

	gettimeofday(&time, NULL);
	start_ms = get_ms(&time);
	while (1)
	{
		gettimeofday(&time, NULL);
		now_ms = get_ms(&time);
		if (now_ms - start_ms > sleep_time)
			break ;
		usleep(200);
	}
}
