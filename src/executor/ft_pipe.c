/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:36:16 by egomes            #+#    #+#             */
/*   Updated: 2022/01/19 13:10:18 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	ft_pipe(int i)
{
	t_mini_shell *ms;
	ms = get_ms();

	// PRIMEIRO
	if (i == 0 && i != ms->size - 1)
	{
		dup2(ms->fd[ms->current_pipe][1], STDOUT_FILENO);
	}
	// ULTIMO
	else if(i > 0 && i == ms->size -1)
	{
		dup2(ms->fd[ms->current_pipe][0], STDIN_FILENO);
	}
	// DO MEIO
	else if (i > 0 && i < ms->size -1)
	{
		dup2(ms->fd[ms->current_pipe][0], STDIN_FILENO);
		dup2(ms->fd[ms->current_pipe + 1][1], STDOUT_FILENO);
	}
	int j = 0;
	while (j < 50)
	{
		close(ms->fd[j][0]);
		close(ms->fd[j][1]);
		j++;
	}

}


// fd[1][0]  ---> grep b --->  fd[2][1]
// fd[2][0]  ---> grep b --->  fd[3][1]
// fd[3][0]  ---> grep b --->  fd[4][1]
// fd[4][0]  ---> grep c --->   1 || file.txt