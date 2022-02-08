/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:49:45 by egomes            #+#    #+#             */
/*   Updated: 2022/02/08 00:49:48 by egomes           ###   ########.fr       */
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
	ms->size = 0;
	ms->group_size = 0;
	ms->current_pipe = 0;
}
