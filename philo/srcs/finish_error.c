/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:50:28 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/10 15:55:23 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	finish_error(char *error_message)
{
	ft_putstr_fd("\x1b[31mError: \x1b[39m", STDERR_FILENO);
	ft_putendl_fd(error_message, STDERR_FILENO);
	return (ERROR);
}
