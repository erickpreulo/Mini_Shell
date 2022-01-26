/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:22:49 by egomes            #+#    #+#             */
/*   Updated: 2022/01/20 15:53:18 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_execve(int i)
{
	t_mini_shell *ms;

	ms = get_ms();
	if (is_file(ms->blocks[i].type))
		return (0);

	ms->pid[i] = fork();
	if (ms->pid[i] == 0)
	{
		ft_pipe(i);
		ft_redirect(i);
		if (execve(ms->blocks[i].path_cmd, ms->blocks[i].argv, NULL) == 0)
			return (1);
	}
	if (i > 0 && i < ms->size -1)
		ms->current_pipe += 1;
	return (0);
}
