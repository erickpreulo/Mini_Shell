/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:52:11 by egomes            #+#    #+#             */
/*   Updated: 2021/12/22 12:08:00 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	echo(char **argv)
{
	pid_t pid1;
	char *cmd;
	int status;
	int fd = 0;

	cmd = "/bin/echo";
	pid1 = fork();
	waitpid(pid1, &status,0);
	if (pid1 == 0)
	{
		if (argv[2])
		{
			fd = open(argv[3], O_WRONLY);
			dup2(fd, 1);
			argv[2] = NULL;
		}
		if (execve(cmd, argv, NULL) == 0)
		{
			printf("Error execve\n");
			return (1);
		}
	}
	return (0);
}
