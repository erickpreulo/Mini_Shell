/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:49:45 by egomes            #+#    #+#             */
/*   Updated: 2022/02/13 18:15:58 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	reset_struct(void)
{
	t_mini_shell	*ms;
	int				i;

	ms = get_ms();
	ms->fd_enter = 0;
	ms->fd_exit = 1;
	ms->sig_exit = 0;
	ms->exit_num = 0;
	ms->has_interrogation_key = false;
	i = -1;
	while (++i < MAX_BLOCKS)
	{
		ms->fd_in[i] = 0;
		ms->fd_out[i] = 0;
	}
	ms->size = 0;
	ms->group_size = 0;
	ms->current_pipe = 0;
}
