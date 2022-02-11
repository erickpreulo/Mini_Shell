/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:49:45 by egomes            #+#    #+#             */
/*   Updated: 2022/02/10 23:03:11 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	start_struct(char **env)
{
	t_mini_shell	*ms;

	ms = get_ms();
	get_env_list(env);
}

void	reset_struct(void)
{
	t_mini_shell	*ms;

	ms = get_ms();
	ms->fd_enter = 0;
	ms->fd_exit = 1;
	for (int i = 0; i < 50; i++)
	{
		ms->fd_in[i] = 0;
		ms->fd_out[i] = 0;
	}
	ms->size = 0;
	ms->group_size = 0;
	ms->current_pipe = 0;
}
