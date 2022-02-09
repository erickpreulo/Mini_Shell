/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:47:51 by egomes            #+#    #+#             */
/*   Updated: 2022/02/09 19:32:43 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_executor(void)
{
	int				i;
	t_mini_shell	*ms;
	// int				status;

	ms = get_ms();
	i = -1;
	while (++i < 50)
		pipe(ms->fd[i]);
	i = -1;
	while (++i < ms->size)
	{
		ft_redirect(i);
		ms->final_status = select_cmd(i);
		if (i > 0 && i < ms->size -1)
			ms->current_pipe += 1;
		if (ms->fd_enter != STDIN_FILENO)
			close(ms->fd_enter);
		if (ms->fd_exit != STDOUT_FILENO)
			close(ms->fd_exit);
	}
	return (0);
}


