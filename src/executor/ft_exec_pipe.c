/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:36:16 by egomes            #+#    #+#             */
/*   Updated: 2022/01/20 04:17:49 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

// int	ft_exec_pipe(int i)
// {
// 	(void)i;
// 	t_mini_shell *ms;
// 	ms = get_ms();

// 	int fd[2];
// 	if (pipe(fd) == -1)
// 		return 1;
	
// 	int pid1 = fork();
// 	if (pid1 < 0)
// 		return 2;

// 	char *cmd = ms->blocks[i].path_cmd;
// 	char **argVec = ms->blocks[i].argv;
// 	char *envVec[] = {NULL};
// 	if (pid1 == 0)
// 	{
// 		dup2(fd[1], STDOUT_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execve(cmd, argVec, envVec);
// 	}
// 	waitpid(pid1, NULL, 0);
// 	int pid2 = fork();
// 	if (pid2 < 0)
// 		return (3);
// 	char *c = ms->blocks[i + 1].path_cmd;
// 	char **a = ms->blocks[i + 1].argv;
// 	char *e[] = {NULL};
// 	if (pid2 == 0)
// 	{
// 		dup2(fd[0], STDIN_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execve(c, a, e);
// 	}
// 	close(fd[0]);
// 	close(fd[1]);
// 	waitpid(pid2, NULL, 0);
// 	return (i);
// }
