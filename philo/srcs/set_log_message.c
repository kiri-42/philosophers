/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_log_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:57:47 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/19 00:27:30 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_log_message(t_management_data *md)
{
	md->log_message[TAKEAFORK].color = F_GREEN;
	md->log_message[EATING].color = F_YELLOW;
	md->log_message[SLEEPING].color = F_LIGHT_BLUE;
	md->log_message[THINKING].color = F_BLUE;
	md->log_message[DIED].color = F_RED;
	md->log_message[TAKEAFORK].message = TAKEAFORK_M;
	md->log_message[EATING].message = EATING_M;
	md->log_message[SLEEPING].message = SLEEPING_M;
	md->log_message[THINKING].message = THINKING_M;
	md->log_message[DIED].message = DIED_M;
}
