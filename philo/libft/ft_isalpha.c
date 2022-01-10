/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:06:15 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/19 21:18:13 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 引数がアルファベットであるか確認する関数 */
int	ft_isalpha(char c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}
