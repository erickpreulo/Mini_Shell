/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:47:51 by egomes            #+#    #+#             */
/*   Updated: 2022/01/20 04:36:42 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int		ft_executor()
{
	int i;
	int pid_final;
	t_mini_shell *ms;
	
	ms = get_ms();
	
	i = 0;
	while (i < 50)
	{
		pipe(ms->fd[i]);
		i++;
	}
	i = 0;
	while (i < ms->size)
	{
		pid_final = ft_execve(i);
		i++;
	}
	i = 0;
	while (i < 50)
	{
		close(ms->fd[i][0]);
		close(ms->fd[i][1]);
		i++;
	}
	i = 0;
	while (i < ms->size)
	{
		waitpid(ms->pid[i], NULL, 0);
		i++;
	}
	return (0);
}
