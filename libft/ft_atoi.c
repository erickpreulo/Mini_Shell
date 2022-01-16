/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 22:54:06 by acanterg          #+#    #+#             */
/*   Updated: 2021/02/17 18:57:05 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char const *str)
{
	int				mult;
	unsigned int	nbr;

	mult = 1;
	nbr = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		mult = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		if (nbr > (nbr * 10) + (*str - 48))
			return (mult == 1 ? -1 : 0);
		nbr = (nbr * 10) + (*str - 48);
		str++;
	}
	return ((int)nbr * mult);
}
