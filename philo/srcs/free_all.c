/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:42:05 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/30 00:05:05 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_all(t_management_data *md)
{
	free(md->thread.philo_treads);
	free(md->thread.monitor_treads);
	free(md->mutex.fork_mutex);
	free(md->philos.eat_cnt);
}
