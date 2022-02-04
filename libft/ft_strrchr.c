/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 00:08:58 by acanterg          #+#    #+#             */
/*   Updated: 2022/02/02 17:42:39 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char*)s + ft_strlen(s) + 1;
	while (--str > s - 1)
		if (*str == (char)c)
			return (str);
	return (NULL);
}
