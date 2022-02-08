/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 12:21:08 by acanterg          #+#    #+#             */
/*   Updated: 2022/02/07 22:49:57 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s)
		return (NULL);
	if (start >= (size_t)ft_strlen(s))
	{
		len = 0;
		start = 0;
	}
	result = malloc((len + 1) * sizeof(char));
	if (!(result))
		return (NULL);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}
