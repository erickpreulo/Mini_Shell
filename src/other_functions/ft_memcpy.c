/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:44:03 by egomes            #+#    #+#             */
/*   Updated: 2021/12/22 20:17:03 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t count;

	count = 0;
	while (count < n)
	{
		((unsigned char*)dst)[count] = ((unsigned char*)src)[count];
		count++;
	}
	return (dst);
}
