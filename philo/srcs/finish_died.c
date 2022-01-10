/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_died.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:31:12 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/11 00:53:47 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	finish_died(int philo_id)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	printf("%lld %d %s\n", get_ms(time), philo_id, DIED);
	exit(0);
}
