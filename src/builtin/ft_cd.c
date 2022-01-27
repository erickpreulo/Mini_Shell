/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:56:13 by egomes            #+#    #+#             */
/*   Updated: 2022/01/27 15:26:48 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char    *get_dir(int i)
{
    t_mini_shell *ms;

    ms = get_ms();
    if (!ms->blocks[i].argv[1])
        return (getenv("HOME"));
    else if (ft_strcmp(ms->blocks[i].argv[1], "-") == 0)
        return (getenv("OLDPWD"));
    else
        return (ms->blocks[i].argv[1]);
}

int is_valid_dir(const char *dir)
{
    DIR *dirptr;

    if (access(dir, F_OK) != -1)
    {
        dirptr = opendir(dir);
        if (dirptr)
        {
            closedir(dirptr);
            return (1);
        }
        else
            return (2);
    }
    return (0);
}

void    change_dir(char *dir)
{
    char *str;

    str = get_current_dir();
    update_env("OLDPWD=", str);
    free(str);
    chdir(dir);
    str = get_current_dir();
    update_env("PWD=", str);
    free(str);
}

int ft_cd(int i)
{
    char *dir;

    int res_dir;
	dir = get_dir(i);
    res_dir = is_valid_dir(dir);
    if (res_dir == 1)
        change_dir(dir);
    else if (res_dir == 2)
        printf("cd: not a directory: %s\n", dir);
    else
        printf("cd: no such file or directory: %s\n", dir);
	return (0);
}
