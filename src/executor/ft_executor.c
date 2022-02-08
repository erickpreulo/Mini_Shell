/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:47:51 by egomes            #+#    #+#             */
/*   Updated: 2022/02/08 00:38:54 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_executor(void)
{
	int				i;
	t_mini_shell	*ms;
	int				status;

	ms = get_ms();
	i = -1;
	while (++i < 50)
		pipe(ms->fd[i]);
	i = -1;
	while (++i < ms->size)
		select_cmd(i);
	i = -1;
	while (++i < ms->size)
	{
		close(ms->fd[i][0]);
		close(ms->fd[i][1]);
		waitpid(ms->pid[i], &status, 0);
	}
	ms->final_status = status;
	return (0);
}
