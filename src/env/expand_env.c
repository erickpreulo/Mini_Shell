/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:12:40 by egomes            #+#    #+#             */
/*   Updated: 2022/02/17 16:11:16 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*get_key(char *str, int *i)
{
	char	*key;
	int		start;

	start = *i;
	while (ft_isalnum(str[*i]))
		*i += 1;
	key = ft_substr(str, start, *i - start);
	return (key);
}

char	*get_str_before(char *str, int *i)
{
	char	*str_bfr;

	while (str[*i] != '$')
		*i += 1;
	str_bfr = ft_substr(str, 0, *i);
	*i += 1;
	return (str_bfr);
}

char	*join_all(char *str, char *bfr, char *env, char *aft)
{
	char			*str_mid;
	char			*str_final;
	t_mini_shell	*ms;

	ms = get_ms();
	str_mid = ft_strjoin(bfr, env);
	str_final = ft_strjoin(str_mid, aft);
	free(str);
	free(bfr);
	free(aft);
	free(str_mid);
	if (ms->has_interrogation_key)
	{
		free(env);
		ms->has_interrogation_key = false;
	}
	return (expand_env(str_final));
}

char	*expand_env(char *str)
{
	int		i;
	char	*str_bfr;
	char	*key;
	char	*str_env;
	char	*str_aft;

	if (ft_strchr(str, '$') == 0)
		return (str);
	i = 0;
	str_bfr = get_str_before(str, &i);
	key = get_key(str, &i);
	str_env = get_env_value(key);
	if (ft_strcmp(key, "?") == 0)
		get_ms()->has_interrogation_key = true;
	free(key);
	str_aft = ft_substr(str, i, ft_strlen(str) - i);
	if (str_env)
		return (join_all(str, str_bfr, str_env, str_aft));
	return (join_all(str, str_bfr, "", str_aft));
}
