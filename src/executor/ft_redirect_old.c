/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_old.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:36:16 by egomes            #+#    #+#             */
/*   Updated: 2022/01/31 00:50:37 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	ft_redirect_old(int i)
{
	t_mini_shell *ms;
	ms = get_ms();

	// PRIMEIRO
	if (ms->blocks[i].first_of_group && ms->fd_in[ms->blocks[i].group])
			dup2(ms->fd_in[ms->blocks[i].group], STDIN_FILENO);
	
	// ULTIMO
	if(ms->blocks[i].last_of_group && ms->fd_out[ms->blocks[i].group])
		dup2(ms->fd_out[ms->blocks[i].group], STDOUT_FILENO);

}
