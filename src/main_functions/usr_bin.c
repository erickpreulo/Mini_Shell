/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usr_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:52:11 by egomes            #+#    #+#             */
/*   Updated: 2021/12/23 04:21:32 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	usr_bin(char **argv)
{
	pid_t pid1;
	char *cmd;
	int status;
	cmd = ft_strjoin("/usr/bin/", argv[0]);
	pid1 = fork();
	waitpid(pid1, &status,0);
	if (pid1 == 0)
	{
		if (execve(cmd, argv, NULL) == -1)
			return (0);
	}
	return (1);
}
