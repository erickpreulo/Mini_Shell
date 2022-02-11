/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_temp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 03:10:03 by acanterg          #+#    #+#             */
/*   Updated: 2022/02/11 04:37:04 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	**get_env_temp(void)
{
	char			**env_temp;
	t_list			*lst;
	t_mini_shell	*ms;
	int				lst_size;
	int				i;

	i = 0;
	ms = get_ms();
	lst = *(ms->lst_env);
	lst_size = ft_lstsize(lst);
	env_temp = malloc((lst_size + 1) * sizeof(char *));
	while (lst)
	{
		env_temp[i++] = ((t_env *)lst->content)->str;
		lst = lst->next;
	}
	env_temp[i] = 0;
	return (env_temp);
}

void	free_lst_env(void)
{
	t_mini_shell	*ms;
	t_list			*curr;
	t_list			*temp;

	ms = get_ms();
	curr = *(ms->lst_env);
	while (curr)
	{
		temp = curr;
		free(((t_env *)curr->content)->key);
		free(((t_env *)curr->content)->str);
		free((t_env *)curr->content);
		curr = curr->next;
		free(temp);
	}
	free(ms->lst_env);
}
