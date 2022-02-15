/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:47:51 by egomes            #+#    #+#             */
/*   Updated: 2022/02/15 16:37:14 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"


void	ft_close_pipe(int i)
{
	t_mini_shell *ms;

	ms = get_ms();
	if (!ms->blocks[i].last_of_group)
		close(ms->blocks[i + 1].pipe[PIPE_WRITE]);
	if (ms->blocks[i].type == T_PIPE)
		close(ms->blocks[i].pipe[PIPE_READ]);
	//if (ms->blocks[i].first_of_group && ms->fd_enter != STDIN_FILENO)
		//close(ms->fd_enter);
	if (ms->blocks[i].last_of_group && ms->fd_exit != STDOUT_FILENO)
		close(ms->fd_exit);
}

int	ft_executor(void)
{
	int				i;
	t_mini_shell	*ms;

	ms = get_ms();
	i = -1;
	while (++i < ms->size)
	{
		//printf("Executing %s ...\n", ms->blocks[i].argv[0]);
		if (ms->fd_in[ms->blocks[i].group] == -1 )
			continue;
		redirect_input(i);
		redirect_output(i);
		ms->final_status = select_cmd(i);
		if (ms->fd_enter != STDIN_FILENO)
			close(ms->fd_enter);
		if (ms->fd_exit != STDOUT_FILENO)
			close(ms->fd_exit);
		//ft_close_pipe(i);
	}
	return (0);
}
