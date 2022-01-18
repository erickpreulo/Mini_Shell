/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:22:49 by egomes            #+#    #+#             */
/*   Updated: 2022/01/14 11:27:08 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_execve(int i, int fd[2])
{
	pid_t pid1;
	t_mini_shell *ms;

	ms = get_ms();
	if (ms->blocks[i].type == T_FILE_APPEND || ms->blocks[i].type == T_FILE_OUT
		|| ms->blocks[i].type == T_FILE_IN)
		return (0);
	printf("aqui:_ %d\n", i);
	pid1 = fork();
	waitpid(pid1, NULL, 0);
	if (pid1 == 0)
	{
		if (i == 0)
			dup2(fd[1], STDOUT_FILENO);
		else
			dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		//ft_exec_pipe(i);
		// find_outfile(argv);
		if (execve(ms->blocks[i].path_cmd, ms->blocks[i].argv, NULL) == 0)
			return (1);
	}
	return (0);
}
