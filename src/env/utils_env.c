/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:23:22 by egomes            #+#    #+#             */
/*   Updated: 2022/02/13 18:17:58 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	update_or_create_env(char *var_env)
{
	t_mini_shell	*ms;
	t_env			*env;
	char			*key;

	ms = get_ms();
	key = ft_strdup(var_env);
	ft_strchr(key, '=')[0] = '\0';
	env = get_env(key);
	free(key);
	if (env)
	{
		free(env->str);
		env->str = ft_strdup(var_env);
		return (0);
	}
	else
	{
		ft_lstadd_back(ms->lst_env, ft_lstnew(create_t_env(var_env)));
		return (0);
	}
	return (1);
}

t_env	*get_env(char *key)
{
	t_mini_shell	*ms;
	t_list			*curr;

	ms = get_ms();
	curr = *(ms->lst_env);
	while (curr)
	{
		if (ft_strcmp(((t_env *)curr->content)->key, key) == 0)
			return ((t_env *)curr->content);
		curr = curr->next;
	}
	return (0);
}

char	*get_env_value(char *key)
{
	t_env			*env;
	char			*value;
	t_mini_shell	*ms;

	ms = get_ms();
	if (ft_strcmp(key, "?") == 0)
	{
		return (ft_itoa(ms->final_status));
	}
	env = get_env(key);
	if (env)
	{
		value = ft_strchr(env->str, '=');
		return (value + 1);
	}
	return (NULL);
}
