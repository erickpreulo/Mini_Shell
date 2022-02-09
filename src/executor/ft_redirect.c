/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:36:16 by egomes            #+#    #+#             */
/*   Updated: 2022/02/09 19:22:27 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	ft_redirect(int i)
{
	t_mini_shell	*ms;

	ms = get_ms();
	// DEFAULT
	ms->fd_enter = STDIN_FILENO;
	ms->fd_exit = STDOUT_FILENO;
	// REDIRECT DE PIPES
	// PRIMEIRO DO GRUPO
	if (ms->blocks[i].first_of_group && !ms->blocks[i].last_of_group)
	{
		if (i == 0)
			ms->fd_exit = ms->fd[ms->current_pipe][1];
		else
		{
			ms->fd_enter = ms->fd[ms->current_pipe][0];
			ms->fd_exit = ms->fd[ms->current_pipe + 1][1];
		}
	}
	// ULTIMO DO GRUPO
	else if (ms->blocks[i].last_of_group && !ms->blocks[i].first_of_group)
	{
		ms->fd_enter = ms->fd[ms->current_pipe][0];
	}
	// MEIO DO GRUPO
	else if (!ms->blocks[i].first_of_group && !ms->blocks[i].last_of_group)
	{
		ms->fd_enter = ms->fd[ms->current_pipe][0];
		ms->fd_exit = ms->fd[ms->current_pipe + 1][1];
	}
	// REDIRECT DE ARQUIVO
	// PRIMEIRO
	if (ms->blocks[i].first_of_group && ms->fd_in[ms->blocks[i].group])
		ms->fd_enter = ms->fd_in[ms->blocks[i].group];
	// ULTIMO
	if (ms->blocks[i].last_of_group && ms->fd_out[ms->blocks[i].group])
		ms->fd_exit = ms->fd_out[ms->blocks[i].group];
}
