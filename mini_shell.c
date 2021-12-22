/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:18:55 by egomes            #+#    #+#             */
/*   Updated: 2021/12/22 11:28:54 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	select_cmd(char *str, char **command)
{
	if (ft_strcmp(str, "ls") == 0)
		ls(command);
	else if (ft_strcmp(str, "pwd") == 0)
		pwd(command);
	else if (ft_strcmp(str, "echo") == 0)
		echo(command);
	else
		return (1);
	return (0);
}

int main(void)
{
	int r;
	char *line;
	char **command;

	line = NULL;
	write(1, "Cyber38@TM % ", 14);
	while ((r = get_next_line(&line)) > 0)
	{
		command = ft_split(line, ' ');
		if (select_cmd(command[0], command))
		{
			printf("%s not found\n", command[0]);
		}
		free(line);
		write(1, "Cyber38@TM % ", 14);
	}
	free(line);
}
