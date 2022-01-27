/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:22:49 by egomes            #+#    #+#             */
/*   Updated: 2022/01/27 13:55:07 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_execve(int i)
{
	t_mini_shell *ms;

	ms = get_ms();

	ms->pid[i] = fork();
	if (ms->pid[i] == 0)
	{
		ft_pipe(i);
		ft_redirect(i);
		if (execve(ms->blocks[i].path_cmd, ms->blocks[i].argv, ms->env) == 0)
			return (1);
	}
	if (i > 0 && i < ms->size -1)
		ms->current_pipe += 1;
	return (0);
}
