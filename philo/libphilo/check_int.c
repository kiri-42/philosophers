/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:20:39 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/13 20:59:52 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"

bool	check_int(const char *str)
{
	long	num;

	num = ft_long_atoi(str);
	return (INT_MIN <= num && num <= INT_MAX);
}
