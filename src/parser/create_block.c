/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:54:07 by acanterg          #+#    #+#             */
/*   Updated: 2022/01/20 16:12:01 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	create_block(char *str)
{
	t_mini_shell *ms;
	int i;

	ms = get_ms();
	i = ms->size;

	ms->blocks[i].is_first = 0;
	ms->blocks[i].is_last = 1;
	ms->blocks[i].type = get_type(str);

	// if (is_file(ms->blocks[i].type))
	// 		ms->is_pipe = 1;
	// if (ms->blocks[i].type == T_PIPE && ms->is_pipe)
	// {
	// 	printf("\nAQUIIII!!!!\n");
	// 	ms->i++;
	// 	ms->size = 0;
	// 	i = ms->size;
	// 	ms->is_pipe = 0;
	// }
	

	ms->blocks[i].str = get_clean_str(str);

	if (ms->blocks[i].type == T_FILE_IN)
		ms->fd_in[ms->group] = open_file_input(ms->blocks[i].str);
	if (ms->blocks[i].type == T_FILE_OUT)
		ms->fd_out[ms->group] = open_file_output(ms->blocks[i].str);
	if (ms->blocks[i].type == T_FILE_APPEND)
		ms->fd_out[ms->group] = open_file_append(ms->blocks[i].str);

	ms->blocks[i].argv = get_argv(ms->blocks[i].str);
	ms->blocks[i].cmd = ms->blocks[i].argv[0];
	ms->blocks[i].path_cmd = get_path_cmd(ms->blocks[i].cmd);

	if (i == 0 || (ms->blocks[i].type == T_PIPE && is_file(ms->blocks[i - 1].type)))
		ms->blocks[i].is_first = ms->group;

	} else {
		ms->blocks[i].is_last = 1;
		ms->blocks[i - 1].is_last = 0;
		}



	print_block(ms->size);
	
	ms->size++;
	if (ms->blocks[i].type == T_FILE_IN
		|| ms->blocks[i].type == T_FILE_OUT
		|| ms->blocks[i].type == T_FILE_APPEND)
		ms->size--;
}
