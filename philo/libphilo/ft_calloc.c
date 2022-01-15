/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:06:09 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/13 20:57:17 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"

/* 引数のサイズ分0埋めされたmallocで確保したメモリを返す関数 */
void	*ft_calloc(size_t n, size_t size)
{
	void	*p;

	p = (void *)malloc(n * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, size * n);
	return (p);
}