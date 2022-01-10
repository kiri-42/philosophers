/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:41:35 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/10 16:08:08 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_arg(int ac, char **av)
{
	(void)av;
	if (!(ac == 5 || ac == 6))
		exit(finish_error("the number of options is incorrect"));
}
