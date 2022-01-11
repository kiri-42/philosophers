/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ms.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:54:44 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/11 16:57:36 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_ms(struct timeval *time)
{
	long long	ms;

	ms = (long)time->tv_sec * 1000 + (long)time->tv_usec / 1000;
	return (ms);
}
