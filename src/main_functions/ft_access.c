/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 05:10:37 by egomes            #+#    #+#             */
/*   Updated: 2022/01/07 06:08:04 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void		ft_access(char **command)
{
	(void) command;
	// char *cmd1;
	// char *cmd2;
	// char *err;

	// cmd1 = ft_strjoin("/bin/", command[0]);
	// cmd2 = ft_strjoin("usr/bin/", command[0]);
	// err = ft_strjoin(command[0], " was not found in /bin/ or /usr/bin/");

	// if (access(cmd1, F_OK) == 0)
	// 	ft_execve(command, cmd1);
	// else if (access(cmd2, F_OK) == 0)
	// 	ft_execve(command, cmd2);
	// else
	// 	printf("%s\n", err);
}
