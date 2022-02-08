/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 22:54:06 by acanterg          #+#    #+#             */
/*   Updated: 2022/02/08 00:05:27 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_digits(int n)
{
	int	counter;

	counter = 0;
	while (n > 0)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}

static char	*handle_exception(int n)
{
	char	*str;

	if (n == 0)
	{
		str = malloc(2 * sizeof(char));
		if (!(str))
			return (NULL);
		ft_strlcpy(str, "0", 2);
	}
	else
	{
		str = malloc(12 * sizeof(char));
		if (!(str))
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
	}
	return (str);
}

int	count(int n)
{
	int	len;

	if (n >= 0)
		len = nbr_digits(n) + 1;
	else
		len = nbr_digits(-n) + 1;
	return (len);
}

int	is_neg(int n)
{
	int	isneg;

	isneg = 0;
	if (n > 0)
		isneg = 1;
	return (isneg);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		isneg;
	int		len;

	if (n == 0 || n == -2147483648)
		return (handle_exception(n));
	len = count(n);
	isneg = is_neg(n);
	if (isneg)
	{
		n = -n;
		len++;
	}
	str = malloc(len * sizeof(char));
	if (!(str))
		return (NULL);
	str[--len] = '\0';
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	if (isneg)
		str[0] = '-';
	return (str);
}
