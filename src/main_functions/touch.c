/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:31:30 by egomes            #+#    #+#             */
/*   Updated: 2021/12/22 20:59:39 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	find_arrow(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '>' && argv[i][1] == '\0')
			return (i + 1);
		i++;
	}
	return (0);
}

int	touch(char *str)
{
	pid_t pid1;
	char *cmd;
	int status;

	char *argVec[] = {"touch", str , NULL};
	cmd = "/usr/bin/touch";
	pid1 = fork();
	waitpid(pid1, &status,0);
	if (pid1 == 0)
	{
		if (execve(cmd, argVec, NULL) == -1)
			printf("Error touch\n");
	}
	return (1);
}