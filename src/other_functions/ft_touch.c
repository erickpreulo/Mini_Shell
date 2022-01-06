/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:31:30 by egomes            #+#    #+#             */
/*   Updated: 2022/01/06 14:19:19 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	find_arrow(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], out_file) == 0
			|| ft_strcmp(argv[i], apend_file) == 0)
		{
			return (i + 1);
			is_out_file = 1;
		i++;
	}
	return (0);
}
