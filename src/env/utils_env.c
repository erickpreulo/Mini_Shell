/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:23:22 by egomes            #+#    #+#             */
/*   Updated: 2022/02/03 21:07:05 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int    update_or_create_env(char *var_env)
{
    t_mini_shell *ms;
    t_env *env;
    char *key;

    ms = get_ms();

	key = ft_strdup(var_env);
	ft_strchr(key, '=')[0] = '\0';
    
    env = get_env(key);
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
    free(key);
    return (1);
}

t_env    *get_env(char *key)
{
    t_mini_shell *ms;
    t_list *curr;

    ms = get_ms();
    curr = *(ms->lst_env);
    while (curr)
    {
        if(ft_strcmp(((t_env *)curr->content)->key, key) == 0)
            return ((t_env *)curr->content);
        curr = curr->next;
    }
    return 0;
}

char    *get_env_value(char *key)
{
    t_env *env;
    char *value;

    env = get_env(key);
    if (env) {
        value = ft_strchr(env->str, '=');
        return (value + 1);
    }
    
    return (NULL);
}

char *expand_env(char *str)
{   
    char *new_str;
    char *new_str2;
    char *str1;
    char *str2;
    char *env_key;
    char *env_value;
    int start;
    int i;
    
    if (ft_strchr(str, '$') == 0)
        return (str);
 
    i = 0;
    while (str[i] != '$')  
        i++;
    str1 = ft_substr(str, 0, i);  // str1 = "o erick setou o "
    i++;
    start = i;
    while (str[i] != ' ' && str[i] != '\0')
        i++;
    env_key = ft_substr(str, start, i - start);
    env_value = get_env_value(env_key);
    str2 = ft_substr(str, i, ft_strlen(str));

    new_str = ft_strjoin(str1, env_value);
    new_str2 = ft_strjoin(new_str, str2);

    // free(str);
    // free(str1);
    // free(str2);
    // free(new_str);
    // //free(env_value);
    // free(env_key);

    return (expand_env(new_str2));
}
