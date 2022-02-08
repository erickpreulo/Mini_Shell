/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:30:12 by egomes            #+#    #+#             */
/*   Updated: 2022/02/08 00:24:57 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_unset(int i)
{
	t_mini_shell	*ms;
	t_list			*curr;
	t_list			*prev;
	char			*var;

	ms = get_ms();
	curr = *(ms->lst_env);
	if (ms->blocks[i].argv[1] != 0)
		var = ms->blocks[i].argv[1];
	else
		return (0);
	curr = *(ms->lst_env);
	if (ft_strcmp(((t_env *)curr->content)->key, var) == 0)
	{
		*(ms->lst_env) = curr->next;
		free(curr);
		return (1);
	}
	prev = curr;
	curr = curr->next;
	while (curr)
	{
		if (ft_strcmp(((t_env *)curr->content)->key, var) == 0)
		{
			prev->next = curr->next;
			free(curr);
			return (1);
		}
		prev = curr;
		curr = curr->next;
	}
	return (0);
}
