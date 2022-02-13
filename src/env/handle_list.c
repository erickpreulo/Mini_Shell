/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:29:05 by egomes            #+#    #+#             */
/*   Updated: 2022/02/13 18:06:12 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

t_env	*create_t_env(char *line)
{
	t_env	*env;
	char	*find;

	env = malloc(sizeof(t_env));
	env->str = ft_strdup(line);
	env->key = ft_strdup(line);
	find = ft_strchr(env->key, '=');
	*find = '\0';
	return (env);
}

void	del_env_content(void *env_temp)
{
	free(((t_env *)env_temp)->key);
	free(((t_env *)env_temp)->str);
	free(env_temp);
}

void	get_env_list(char **env)
{
	t_mini_shell	*ms;
	int				i;

	ms = get_ms();
	ms->env = env;
	ms->lst_env = malloc(sizeof(t_list *));
	*ms->lst_env = NULL;
	i = 0;
	while (env[i])
	{
		ft_lstadd_back(ms->lst_env, ft_lstnew(create_t_env(env[i])));
		i++;
	}
}
