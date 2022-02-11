/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:22:49 by egomes            #+#    #+#             */
/*   Updated: 2022/02/11 06:54:54 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	exec_child(int i, char **env_temp)
{
	t_mini_shell	*ms;

	ms = get_ms();
	dup2(ms->fd_enter, STDIN_FILENO);
	dup2(ms->fd_exit, STDOUT_FILENO);
	execve(ms->blocks[i].path_cmd, ms->blocks[i].argv, env_temp);
	return (1);
}

int	exec_parent(pid_t pid, char **env_temp)
{
	int				status;
	int				ret;

	ret = waitpid(pid, &status, 0);
	free(env_temp);
	if (ret == -1)
		return (EXIT_FAILURE);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (0);
}

int	ft_execve(int i)
{
	pid_t			pid;
	char			**env_temp;

	env_temp = get_env_temp();
	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
		return (exec_child(i, env_temp));
	else
		return (exec_parent(pid, env_temp));
	return (0);
}
