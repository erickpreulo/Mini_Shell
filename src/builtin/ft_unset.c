/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:30:12 by egomes            #+#    #+#             */
/*   Updated: 2022/02/13 18:02:43 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	unset_after(t_list *curr, t_list *prev, char *var)
{
	while (curr)
	{
		if (ft_strcmp(((t_env *)curr->content)->key, var) == 0)
		{
			prev->next = curr->next;
			ft_lstdelone(curr, del_env_content);
			return (0);
		}
		prev = curr;
		curr = curr->next;
	}
	return (1);
}

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
		return (1);
	curr = *(ms->lst_env);
	if (ft_strcmp(((t_env *)curr->content)->key, var) == 0)
	{
		*(ms->lst_env) = curr->next;
		ft_lstdelone(curr, del_env_content);
		return (0);
	}
	prev = curr;
	curr = curr->next;
	return (unset_after(prev, curr, var));
}
