/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:35:06 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/19 00:22:02 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_management_data	md;

	// if (check_arg(ac, av))
	// 	return (ERROR);
	// printf("%s %d\n", __FILE__, __LINE__);
	// if (set_mdata(ac, av, &mdata))
	// 	return (ERROR);
	// printf("%s %d\n", __FILE__, __LINE__);
	// if (!run_simulation(&mdata))
	// 	return (ERROR);
	// printf("%s %d\n", __FILE__, __LINE__);
	// return (SUCCESS);
	if (check_arg(ac, av) == SUCCESS && \
		set_mdata(ac, av, &md) == SUCCESS && \
		run_simulation(&md) == SUCCESS)
		return (SUCCESS);
	return (ERROR);
}
