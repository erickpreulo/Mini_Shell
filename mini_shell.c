/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:18:55 by egomes            #+#    #+#             */
/*   Updated: 2021/12/20 20:30:21 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int main(void)
{
	int r;
	char *line;
	char **command;

	line = NULL;
	while ((r = get_next_line(&line)) > 0)
	{
		command = ft_split(line, ' ');
		if (ft_strcmp(command[0], "ls") == 0)
			ls(command);
		else {
			printf("%s not found\n", command[0]);
			// perror("not found\n");
		}
		free(line);
	}
	free(line);
}
