/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:35:06 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/18 17:12:15 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_management_data	mdata;

	check_arg(ac, av);
	set_mdata(ac, av, &mdata);
	run_simulation(&mdata);
	free_mdata(&mdata);
	exit(0);
}
