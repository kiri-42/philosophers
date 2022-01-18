/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:41:35 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/18 17:27:57 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

void	check_arg(int ac, char **av)
{
	size_t	ac_i;
	size_t	char_i;

	if (!(ac == 5 || ac == 6))
		finish_error(ARG_ERROR);
	ac_i = 1;
	while (ac_i < (size_t)ac)
	{
		char_i = 0;
		while (av[ac_i][char_i] != '\0')
		{
			if (!(ft_isdigit(av[ac_i][char_i])))
				finish_error(ARG_ERROR);
			char_i++;
		}
		if (!(check_int(av[ac_i])))
			finish_error(ARG_ERROR);
		ac_i++;
	}
}
