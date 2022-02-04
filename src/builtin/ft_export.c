/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:30:39 by egomes            #+#    #+#             */
/*   Updated: 2022/02/03 00:07:52 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	sort_argv(char **str, int size)
{
	int		i;
	int		m;
	char	*hold;

	i = 0;
	while (i < size)
	{
		m = i + 1;
		while (m < size)
		{
			if (ft_strcmp(str[i], str[m]) > 0)
			{
				hold = str[i];
				str[i] = str[m];
				str[m] = hold;
			}
			m++;
		}
		i++;
	}
}

char	**get_sorted_env(void)
{
	t_mini_shell *ms;
	t_list *curr;
	int size;
	char **arr;

	ms = get_ms();
	size = 0;
	curr = *(ms->lst_env);
	arr = malloc(256*sizeof(char *));
	while (curr)
	{
		arr[size] = ((t_env *)curr->content)->key;
		size++;
		curr = curr->next;
	}
	arr[size] = 0;
	sort_argv(arr, size);
	return (arr);
}

void	only_export(void)
{
	t_mini_shell *ms;
	t_list	*curr;
	t_env	*content;
	char	**sorted;
	int		i;

	ms = get_ms();
	sorted = get_sorted_env();
	
	i = -1;
	while (sorted[++i])
	{
		curr = *(ms->lst_env);
		while (curr)
		{
			content = (t_env *)curr->content;
			if (ft_strcmp(sorted[i], content->key) != 0)
			{
				curr = curr->next;
				continue;
			}
			ft_putstr_fd("declare -x ", ms->fd_exit);
			ft_putstr_fd(content->key, ms->fd_exit);
			ft_putstr_fd("=\"", ms->fd_exit);
			ft_putstr_fd(ft_strchr(content->str, '=') + 1, ms->fd_exit);
			ft_putendl_fd("\"", ms->fd_exit);
			break;
		}
	}
}

int	ft_export(int i)
{
	t_mini_shell *ms;

	ms = get_ms();
	if (ms->blocks[i].argv[1] == 0)
		only_export();
	else if (ft_strchr(ms->blocks[i].argv[1], '='))
		update_or_create_env(ms->blocks[i].argv[1]);

	return (0);
}
