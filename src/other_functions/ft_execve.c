/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:22:49 by egomes            #+#    #+#             */
/*   Updated: 2022/01/14 11:27:08 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_execve(int i)
{
	pid_t pid1;
	int status;
	t_mini_shell *ms;

	ms = get_ms();
	if (ms->blocks[i].type == T_FILE_APPEND || ms->blocks[i].type == T_FILE_OUT
		|| ms->blocks[i].type == T_FILE_IN)
		return (0);
	pid1 = fork();
	waitpid (pid1, &status,0);
	if (pid1 == 0)
	{
		ft_exec_pipe(i);
		// find_outfile(argv);
		if (execve(ms->blocks[i].path_cmd, ms->blocks[i].argv, NULL) == 0)
			return (1);
	}
	return (0);
}
