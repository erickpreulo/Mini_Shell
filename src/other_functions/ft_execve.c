/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:22:49 by egomes            #+#    #+#             */
/*   Updated: 2022/01/03 12:32:25 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_execve(char **argv, int i, char *str)
{
	pid_t pid1;
	char *cmd;
	int status;
	int fd;

	cmd = str;
	pid1 = fork();
	waitpid(pid1, &status,0);
	if (pid1 == 0)
	{
		if (argv[i - 1])
		{
			fd = open(argv[i], O_WRONLY);
			dup2(fd, 1);
			argv[i - 1] = NULL;
		}
		if (execve(cmd, argv, NULL) == 0)
			return (0);
	}
	return (1);
}