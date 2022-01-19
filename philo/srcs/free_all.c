/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:42:05 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/19 00:31:43 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_mdata(t_management_data *md)
{
	free(md->thread.philo_treads);
	free(md->thread.monitor_treads);
	free(md->mutex.fork_mutex);
	free(md->philos.eat_cnt);
}

void	free_adata(t_action_data *ad)
{
	free(ad->thread->philo_treads);
	free(ad->thread->monitor_treads);
	free(ad->mutex->fork_mutex);
	free(ad->philos->eat_cnt);
}
