/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 01:27:57 by egomes            #+#    #+#             */
/*   Updated: 2022/02/15 21:27:03 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	close_fds(t_mini_shell *ms)
{
	int	i;

	i = -1;
	while (++i < ms->group_size)
	{
		if (i > 0)
		{
			close(ms->blocks[i].pipe[PIPE_READ]);
			close(ms->blocks[i].pipe[PIPE_WRITE]);
		}
		if (ms->fd_in[i] > 0)
		{
			close(ms->fd_in[i]);
			ms->fd_in[i] = 0;
		}
		if (ms->fd_out[i] > 0)
		{
			close(ms->fd_out[i]);
			ms->fd_out[i] = 0;
		}
	}
}

void	clean_blocks_args(t_mini_shell *ms)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ms->size)
	{
		if (ms->blocks[i].argv)
		{
			j = -1;
			while (ms->blocks[i].argv[++j])
				free(ms->blocks[i].argv[j]);
			free(ms->blocks[i].argv);
			ms->blocks[i].argv = 0;
		}
	}
}

void	clean_blocks_strs(t_mini_shell *ms)
{
	int	i;

	i = -1;
	while (++i < ms->size)
	{
		if (ms->blocks[i].str)
		{
			free(ms->blocks[i].str);
			ms->blocks[i].str = 0;
		}
		if (ms->blocks[i].path_cmd)
		{
			free(ms->blocks[i].path_cmd);
			ms->blocks[i].path_cmd = 0;
		}		
	}
}

void	clean_up()
{
	t_mini_shell	*ms;

	ms = get_ms();
	close_fds(ms);
	clean_blocks_args(ms);
	clean_blocks_strs(ms);
	unlink(".temp");
}
