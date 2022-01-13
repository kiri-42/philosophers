/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:04:08 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/13 20:54:49 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"

char	*free_and_return(char *free_variable)
{
	free(free_variable);
	return (NULL);
}
