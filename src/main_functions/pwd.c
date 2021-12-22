/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:52:11 by egomes            #+#    #+#             */
/*   Updated: 2021/12/22 10:49:27 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	pwd(char **argv)
{
	pid_t pid1;
	char *cmd;
    int status;

	cmd = "/bin/pwd";
	pid1 = fork();
	waitpid(pid1, &status,0);
	if (pid1 == 0)
	{
		if (execve(cmd, argv, NULL) == 0)
		{
			printf("Error execve\n");
			return (1);
		}
	}
	return (0);
}