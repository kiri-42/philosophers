/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_log_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:57:47 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/17 02:55:57 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_log_message(t_management_data *mdata)
{
	mdata->log_message[TAKEAFORK].color = F_GREEN;
	mdata->log_message[EATING].color = F_YELLOW;
	mdata->log_message[SLEEPING].color = F_LIGHT_BLUE;
	mdata->log_message[THINKING].color = F_BLUE;
	mdata->log_message[DIED].color = F_RED;
	mdata->log_message[TAKEAFORK].message = TAKEAFORK_M;
	mdata->log_message[EATING].message = EATING_M;
	mdata->log_message[SLEEPING].message = SLEEPING_M;
	mdata->log_message[THINKING].message = THINKING_M;
	mdata->log_message[DIED].message = DIED_M;
}
