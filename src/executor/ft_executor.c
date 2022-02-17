/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:47:51 by egomes            #+#    #+#             */
/*   Updated: 2022/02/17 15:46:37 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	open_pipe(t_mini_shell *ms, int i)
{
	if (i < ms->size - 1)
		pipe(ms->blocks[i + 1].pipe);
}

void	close_pipes(t_mini_shell *ms, int i)
{
	if (ms->fd_enter != STDIN_FILENO)
		close(ms->fd_enter);
	if (ms->fd_exit != STDOUT_FILENO)
		close(ms->fd_exit);
	if (i == 0 && ms->size > 1)
		return ((void) close(ms->blocks[i + 1].pipe[PIPE_WRITE]));
	if (i == ms->size - 1)
		return ((void) close(ms->blocks[i].pipe[PIPE_READ]));
	close(ms->blocks[i].pipe[PIPE_READ]);
	close(ms->blocks[i + 1].pipe[PIPE_WRITE]);
}

int	ft_executor(void)
{
	int				i;
	t_mini_shell	*ms;

	ms = get_ms();
	i = -1;
	while (++i < ms->size)
	{
		open_pipe(ms, i);
		if (ms->fd_in[ms->blocks[i].group] == -1)
			continue ;
		redirect_input(i);
		redirect_output(i);
		ms->final_status = select_cmd(i);
		close_pipes(ms, i);
	}
	return (0);
}
