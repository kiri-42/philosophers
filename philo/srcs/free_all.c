/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:42:05 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/18 17:10:45 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_mdata(t_management_data *mdata)
{
	free(mdata->thread.philo_treads);
	free(mdata->thread.monitor_treads);
	free(mdata->mutex.fork_mutex);
	free(mdata->philos.eat_cnt);
}

void	free_adata(t_action_data *adata)
{
	free(adata->thread->philo_treads);
	free(adata->thread->monitor_treads);
	free(adata->mutex->fork_mutex);
	free(adata->philos->eat_cnt);
}
