/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:12:40 by egomes            #+#    #+#             */
/*   Updated: 2022/02/13 18:15:28 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*get_key(char *str, int *i)
{
	char	*key;
	int		start;

	start = *i;
	while (str[*i] != ' ' && str[*i] != '\0')
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

// char *expand_env(char *str)
// {   
//	 char *new_str;
//     char *new_str2;
//     char *str1;
//     char *str2;
//     char *env_key;
//     char *env_value;
//     int start;
//     int i;

//     if (ft_strchr(str, '$') == 0)
//         return (str);

//     start = i;
//     while (str[i] != ' ' && str[i] != '\0')
//         i++;
//     env_key = ft_substr(str, start, i - start);
//     env_value = get_env_value(env_key);
//     str2 = ft_substr(str, i, ft_strlen(str));

//     new_str = ft_strjoin(str1, env_value);
//     new_str2 = ft_strjoin(new_str, str2);

//     free(str);
//     free(str1);
//     free(str2);
//     free(new_str);
//     //free(env_value);
//     free(env_key);

//     return (expand_env(new_str2));
// }
