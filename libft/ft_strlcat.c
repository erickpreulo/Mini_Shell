/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 22:53:14 by acanterg          #+#    #+#             */
/*   Updated: 2022/02/07 22:51:19 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_s;
	size_t	len_d;

	len_s = ft_strlen((char *)src);
	len_d = ft_strlen(dst);
	if (len_d >= dstsize)
		return (dstsize + len_s);
	if (len_s < (dstsize - len_d))
	{
		ft_memcpy(dst + len_d, src, len_s);
		dst[len_d + len_s] = '\0';
	}
	else
	{
		ft_memcpy(dst + len_d, src, dstsize - len_d - 1);
		dst[dstsize - 1] = '\0';
	}
	return (len_d + len_s);
}
