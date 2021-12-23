/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:20:13 by egomes            #+#    #+#             */
/*   Updated: 2021/12/22 16:32:01 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	null_buffer(char *buffer)
{
	int	i;

	if (!buffer)
		return (-1);
	i = 0;
	while (i < 100000)
		buffer[i++] = '\0';
	return (0);
}

int	get_next_line(char **line)
{
	int		i;
	int		r;
	char	*buffer;
	char	c;

	buffer = (char *)malloc(100000);
	null_buffer(buffer);
	i = 0;
	c = '0';
	r = 1;
	while (r != 0 && c != '\n' && c != '\0')
	{
		r = read(0, &c, 1);
		if (c == '\n' && c == '\0' && r == 0)
			break ;
		if (c != '\n' && c != '\0' && r != 0)
			buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
	*line = buffer;
	return (r);
}
