/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:47:51 by egomes            #+#    #+#             */
/*   Updated: 2022/02/11 07:08:32 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_executor(void)
{
	int				i;
	t_mini_shell	*ms;

	ms = get_ms();
	i = -1;
	while (++i < ms->size)
	{
		pipe(ms->fd[i]);
		ft_redirect(i);
		if (ms->fd_in[ms->blocks[i].group] != -1)
			ms->final_status = select_cmd(i);
		if (i > 0 && i < ms->size -1)
			ms->current_pipe += 1;
		if (ms->fd_enter != STDIN_FILENO || is_file(ms->blocks[i].type))
			close(ms->fd_enter);
		if (ms->fd_exit != STDOUT_FILENO || is_file(ms->blocks[i].type))
			close(ms->fd_exit);
	}
	return (0);
}
