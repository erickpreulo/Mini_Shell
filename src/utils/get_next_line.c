/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line .c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:39:00 by egomes            #+#    #+#             */
/*   Updated: 2022/01/31 01:34:37 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int		get_next_line(char **line)
{
	int i;
	int r;
	char *buffer;
	char c;

	if (!(buffer = (char *)malloc(100000)))
		return (-1);
	i = 0;
    while (i < 100000)
        buffer[i++] = '\0';
    i = 0;
	while ((r = read(0, &c, 1)) && c != '\n' && c != '\0')
	{
        if (c == '\n' || c == '\0')
            break;
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
	*line = buffer;
	return (r);
}
