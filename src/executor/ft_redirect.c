/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:36:16 by egomes            #+#    #+#             */
/*   Updated: 2022/01/20 03:58:43 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	ft_redirect(int i)
{
	t_mini_shell *ms;
	ms = get_ms();

	// PRIMEIRO
	if (i == 0)
	{
		if(ms->fd_in)
			dup2(ms->fd_in, STDIN_FILENO);
	}
	// ULTIMO
	if(i == ms->size -1)
	{
		if(ms->fd_out)
			dup2(ms->fd_out, STDOUT_FILENO);
	}
}
