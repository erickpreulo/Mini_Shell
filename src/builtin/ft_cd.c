/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:56:13 by egomes            #+#    #+#             */
/*   Updated: 2022/02/11 06:42:10 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*get_dir(int i)
{
	t_mini_shell	*ms;

	ms = get_ms();
	if (!ms->blocks[i].argv[1])
		return (get_env_value("HOME"));
	else if (ft_strcmp(ms->blocks[i].argv[1], "-") == 0)
		return (get_env_value("OLDPWD"));
	else
		return (ms->blocks[i].argv[1]);
}

int	is_valid_dir(const char *dir)
{
	DIR	*dirptr;

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

void	change_dir(char *dir)
{
	char	*str;
	char	*str_join;

	str = get_current_dir();
	str_join = ft_strjoin("OLDPWD=", str);
	update_or_create_env(str_join);
	free(str);
	free(str_join);
	chdir(dir);
	str = get_current_dir();
	str_join = ft_strjoin("PWD=", str);
	update_or_create_env(str_join);
	free(str);
	free(str_join);
}

int	ft_cd(int i)
{
	char	*dir;
	int		res_dir;

	dir = ft_strdup(get_dir(i));
	res_dir = is_valid_dir(dir);
	if (res_dir == 1)
		change_dir(dir);
	else if (res_dir == 2) {
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(dir, 2);
		ft_putendl_fd(": Not a directory", 2);
		free(dir);
		return (1);
	}
	else
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(dir, 2);
		ft_putendl_fd(": No such file or directory", 2);
		free(dir);
		return (1);
	}
	free(dir);
	return (0);
}
