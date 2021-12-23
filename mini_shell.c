/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:18:55 by egomes            #+#    #+#             */
/*   Updated: 2021/12/23 04:21:02 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	select_cmd(char **command)
{
	int i;

	if (ft_strcmp(command[0], "exit") == 0)
		exit(0);
	if (ft_strcmp(command[0], "cd") == 0)
	{
		chdir(command[1]);
		return (0);
	}
	i = find_arrow(command);
	if (i != 0)
		touch(command[i]);
	if (bin(command, i))
		return (0);
	else if (usr_bin(command))
		return (0);
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
		if (select_cmd(command))
		{
			printf("%s not found\n", command[0]);
		}
		free(line);
		write(1, "Cyber38@TM % ", 14);
	}
	free(line);
}
