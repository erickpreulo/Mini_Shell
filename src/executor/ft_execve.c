/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:22:49 by egomes            #+#    #+#             */
/*   Updated: 2022/02/08 00:39:43 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_execve(int i)
{
	t_mini_shell	*ms;
	int				j;

	ms = get_ms();
	ms->pid[i] = fork();
	if (ms->pid[i] == 0)
	{
		dup2(ms->fd_enter, STDIN_FILENO);
		dup2(ms->fd_exit, STDOUT_FILENO);
		j = 0;
		while (j < ms->size)
		{
			close(ms->fd[j][0]);
			close(ms->fd[j][1]);
			j++;
		}
		if (execve(ms->blocks[i].path_cmd, ms->blocks[i].argv, ms->env) == 0)
			return (1);
	}
	return (0);
}
