/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:36:16 by egomes            #+#    #+#             */
/*   Updated: 2022/02/17 15:29:57 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	redirect_input(int i)
{
	t_mini_shell	*ms;

	ms = get_ms();
	ms->fd_enter = STDIN_FILENO;
	if (ms->blocks[i].type == T_PIPE)
		ms->fd_enter = ms->blocks[i].pipe[PIPE_READ];
	if (ms->blocks[i].last_of_group && ms->fd_in[ms->blocks[i].group])
		ms->fd_enter = ms->fd_in[ms->blocks[i].group];
}

void	redirect_output(int i)
{
	t_mini_shell	*ms;

	ms = get_ms();
	ms->fd_exit = STDOUT_FILENO;
	if (!ms->blocks[i].last_of_group)
		ms->fd_exit = ms->blocks[i + 1].pipe[PIPE_WRITE];
	if (ms->blocks[i].last_of_group && ms->fd_out[ms->blocks[i].group])
		ms->fd_exit = ms->fd_out[ms->blocks[i].group];
	else if (ms->blocks[i].last_of_group && i < ms->size - 1)
		ms->fd_exit = ms->blocks[i + 1].pipe[PIPE_WRITE];
}
