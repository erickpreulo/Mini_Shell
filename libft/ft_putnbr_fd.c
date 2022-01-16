/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 12:26:18 by acanterg          #+#    #+#             */
/*   Updated: 2021/02/18 16:01:51 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	holder;

	holder = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		holder = -n;
	}
	if (holder >= 10)
	{
		ft_putnbr_fd(holder / 10, fd);
		ft_putnbr_fd(holder % 10, fd);
	}
	else
		ft_putchar_fd(holder + '0', fd);
}
