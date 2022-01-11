/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_log.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:34:46 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/11 15:38:57 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	put_log(struct timeval time, int philo_id, char *message)
{
	printf("%lld %d %s\n", get_ms(time), philo_id, message);
}
