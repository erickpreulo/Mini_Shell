/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 22:50:54 by acanterg          #+#    #+#             */
/*   Updated: 2021/02/17 16:28:35 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest_p;
	unsigned char	*src_p;
	unsigned char	ch;
	size_t			i;

	dest_p = (unsigned char *)dest;
	src_p = (unsigned char *)src;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dest_p[i] = src_p[i];
		if (dest_p[i] == ch)
			return ((unsigned char *)dest_p + i + 1);
		i++;
	}
	return (NULL);
}
