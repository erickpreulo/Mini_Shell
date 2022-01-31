/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_old.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:36:16 by egomes            #+#    #+#             */
/*   Updated: 2022/01/31 16:46:00 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	ft_pipe_old(int i)
{
	t_mini_shell *ms;
	ms = get_ms();

	// PRIMEIRO DO GRUPO
	if (ms->blocks[i].first_of_group && !ms->blocks[i].last_of_group)
	{
		if (i == 0)
			dup2(ms->fd[ms->current_pipe][1], STDOUT_FILENO);
		else
		{
			dup2(ms->fd[ms->current_pipe][0], STDIN_FILENO);
			dup2(ms->fd[ms->current_pipe + 1][1], STDOUT_FILENO);
		}
	}
	// ULTIMO DO GRUPO
	else if(ms->blocks[i].last_of_group && !ms->blocks[i].first_of_group)
	{
		dup2(ms->fd[ms->current_pipe][0], STDIN_FILENO);
	}
	// MEIO DO GRUPO
	else if (!ms->blocks[i].first_of_group && !ms->blocks[i].last_of_group)
	{
		dup2(ms->fd[ms->current_pipe][0], STDIN_FILENO);
		dup2(ms->fd[ms->current_pipe + 1][1], STDOUT_FILENO);
	}
	int j = 0;
	while (j < ms->size)
	{
		close(ms->fd[j][0]);
		close(ms->fd[j][1]);
		j++;
	}
}
