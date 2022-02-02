/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:25:45 by egomes            #+#    #+#             */
/*   Updated: 2022/02/01 20:21:52 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_env()
{
	t_mini_shell *ms;
	t_list *curr;
	
	ms = get_ms();
	curr = *(ms->lst_env);

	while (curr)
	{
		ft_putendl_fd((char *)curr->content, ms->fd_exit);
		curr = curr->next;
	}

	return (0);
}
