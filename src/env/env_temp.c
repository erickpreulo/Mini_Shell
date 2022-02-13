/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_temp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 03:10:03 by acanterg          #+#    #+#             */
/*   Updated: 2022/02/13 18:06:04 by acanterg         ###   ########.fr       */
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

	ms = get_ms();
	ft_lstclear(ms->lst_env, del_env_content);
	free(ms->lst_env);
}
