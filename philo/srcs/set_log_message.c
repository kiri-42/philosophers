/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_log_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:57:47 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/13 16:58:31 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_log_message(void)
{
	g_log_message[TAKEAFORK].color = F_GREEN;
	g_log_message[EATING].color = F_YELLOW;
	g_log_message[SLEEPING].color = F_LIGHT_BLUE;
	g_log_message[THINKING].color = F_BLUE;
	g_log_message[DIED].color = F_RED;
	g_log_message[TAKEAFORK].message = TAKEAFORK_M;
	g_log_message[EATING].message = EATING_M;
	g_log_message[SLEEPING].message = SLEEPING_M;
	g_log_message[THINKING].message = THINKING_M;
	g_log_message[DIED].message = DIED_M;
}
