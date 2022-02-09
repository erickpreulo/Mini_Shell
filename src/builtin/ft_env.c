/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:25:45 by egomes            #+#    #+#             */
/*   Updated: 2022/02/09 19:31:06 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_env(void)
{
	t_mini_shell	*ms;
	t_list			*curr;

	ms = get_ms();
	curr = *(ms->lst_env);
	while (curr)
	{
		ft_putendl_fd(((t_env *)curr->content)->str, ms->fd_exit);
		curr = curr->next;
	}
	return (7);
}
