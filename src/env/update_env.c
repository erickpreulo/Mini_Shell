/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:23:22 by egomes            #+#    #+#             */
/*   Updated: 2022/01/27 15:48:57 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void    update_env(char *key, char *newstr)
{
    t_mini_shell *ms;
    int i;

    ms = get_ms();
    i = 0;
    while (ms->env[i])
    {
        if(ft_strncmp(ms->env[i], key, ft_strlen(key)) == 0)
        {
            free(ms->env[i]);
            ms->env[i] = ft_strjoin(key, newstr);
            break;
        }
        i++;
    }
}
