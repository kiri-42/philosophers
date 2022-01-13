/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:42:05 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/13 23:42:46 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_all(void)
{
	free(g_tread_data.philo_treads);
	free(g_tread_data.monitor_treads);
	free(g_mutex_data.fork_mutex);
}
