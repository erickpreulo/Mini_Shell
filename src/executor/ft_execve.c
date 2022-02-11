/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:22:49 by egomes            #+#    #+#             */
/*   Updated: 2022/02/10 22:42:24 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_execve(int i)
{
	t_mini_shell	*ms;
	int 			status;
	pid_t  			pid;

	ms = get_ms();
	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
	{
		dup2(ms->fd_enter, STDIN_FILENO);
		dup2(ms->fd_exit, STDOUT_FILENO);
		execve(ms->blocks[i].path_cmd, ms->blocks[i].argv, ms->env);
		return(1);
	}
	else {
		if (waitpid(pid, &status, 0) == -1)
			return (EXIT_FAILURE);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			return (128 + WTERMSIG(status));
		return (0);
	}
	return (0);
}
