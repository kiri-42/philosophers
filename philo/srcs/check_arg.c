/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:41:35 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/10 17:01:59 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_arg(int ac, char **av)
{
	size_t	ac_i;
	size_t	char_i;

	if (!(ac == 5 || ac == 6))
		finish_error("the number of options is incorrect");
	ac_i = 1;
	while (ac_i < (size_t)ac)
	{
		char_i = 0;
		while (av[ac_i][char_i] != '\0')
		{
			if (!(ft_isdigit(av[ac_i][char_i])))
				finish_error("non-numeric character was detected in the options");
			char_i++;
		}
		if (!(check_int(av[ac_i])))
			finish_error("the option string does not fit in the int range");
		ac_i++;
	}
}
