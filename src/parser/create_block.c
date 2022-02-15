/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:54:07 by acanterg          #+#    #+#             */
/*   Updated: 2022/02/15 21:25:57 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	adjust_group(int i, t_mini_shell *ms)
{
	if (!ms->searching_new_group && i > 0)
		ms->blocks[i - 1].last_of_group = false;
	if (ms->searching_new_group)
	{
		ms->searching_new_group = false;
		ms->group_size++;
	}
	ms->blocks[i].group = ms->group_size;
}


void clean_up_block(t_mini_shell *ms, int i)
{
	int	j;
	
	if (ms->blocks[i].argv)
	{
		j = -1;
		while (ms->blocks[i].argv[++j])
			free(ms->blocks[i].argv[j]);
		free(ms->blocks[i].argv);
		ms->blocks[i].argv = 0;
	}
	if (ms->blocks[i].str)
	{
		free(ms->blocks[i].str);
		ms->blocks[i].str = 0;
	}
}


void	handle_file(t_mini_shell *ms, int i)
{
	ms->searching_new_group = true;
	if (ms->fd_in[ms->group_size] != -1)
	{
		if (ms->blocks[i].type == T_FILE_IN)
			ms->fd_in[ms->group_size] = open_file_input(ms->blocks[i].str,
					ms->group_size);
		if (ms->blocks[i].type == T_FILE_OUT)
			ms->fd_out[ms->group_size] = open_file_output(ms->blocks[i].str,
					ms->group_size);
		if (ms->blocks[i].type == T_FILE_APPEND)
			ms->fd_out[ms->group_size] = open_file_append(ms->blocks[i].str,
					ms->group_size);
		if (ms->blocks[i].type == T_FILE_DELIMITER)
			ms->fd_in[ms->group_size] = open_file_delimiter(ms->blocks[i].str,
					ms->blocks[i].argv[0], ms->group_size);
	}
	clean_up_block(ms, i);
}

void	create_block(char *str)
{
	t_mini_shell	*ms;
	int				i;

	ms = get_ms();
	i = ms->size;
	ms->blocks[i].last_of_group = true;
	ms->blocks[i].type = get_type(str);
	ms->blocks[i].str = get_clean_str(str);
	ms->blocks[i].argv = get_argv(ms->blocks[i].str);
	if (is_file(ms->blocks[i].type))
		return (handle_file(ms, i));
	ms->blocks[i].cmd = ms->blocks[i].argv[0];
	ms->blocks[i].path_cmd = get_path_cmd(ms->blocks[i].cmd);
	if (ms->blocks[i].type == T_PIPE)
		pipe(ms->blocks[i].pipe);
	adjust_group(i, ms);
	ms->size++;
}
