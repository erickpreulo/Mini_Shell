/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:22:49 by egomes            #+#    #+#             */
/*   Updated: 2022/01/03 15:56:17 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_execve(char **argv, int i, char *cmd)
{
	pid_t pid1;
	int status;
	int fd;

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
			return (1);
	}
	return (0);
}