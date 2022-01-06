/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_arrow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:31:30 by egomes            #+#    #+#             */
/*   Updated: 2022/01/06 15:00:40 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	find_arrow(char **argv)
{
	int i;
	t_mini_shell *ms;

	ms = get_ms();
	i = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], OUT_FILE) == 0
			|| ft_strcmp(argv[i], APEND_FILE) == 0)
		{
			return (i + 1);
			ms->is_out_file = 1;
		}
		i++;
	}
	return (0);
}


// echo "erick" | ls -l alexandre | cat -e | grep "ls" < erick.txt

// while (1)
// {
// 	//block -> i = 0
// 	block[i]->argv = [ "ls", "-l", "alexandre"]
// 	block[i]->type = CMD
// 	block[i]->cmd = block->argv[i];
// 	block[i]->path_cmd = get_path_cmd(i);
// 	block[i]->fd_pipe[]

// 	//block -> i = 1
// 	block[i]->argv = [ "cat", "-e"]
// 	block[i]->type = PIPE // "cmd", "file_in", "file_out", "file_append", "pipe"
// 	block[i]->cmd = block->argv[i];
// 	block[i]->path_cmd = get_path_cmd(i);
// 	block[i]->fd_pipe

// 	//block -> i = 2
// block[i]->argv = [ "grep", "ls"]
// 	block[i]->type = "pipe" // "cmd", "file_in", "file_out", "file_append", "pipe"
// 	block[i]->cmd = block->argv[i];
// 	block[i]->path_cmd = get_path_cmd(i);
// 	block[i]->fd_pipe

// 	//block -> i = 3
// 	block[i]->argv = [ "erick.txt" ]
// 	block[i]->type = "file_in" // "cmd", "file_in", "file_out", "file_append", "pipe"
// 	block[i]->cmd = block->argv[i];
// 	block[i]->path_cmd = get_path_cmd(i);
// 	block[i]->fd_pipe
