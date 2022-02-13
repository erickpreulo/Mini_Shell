/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:56:13 by egomes            #+#    #+#             */
/*   Updated: 2022/02/13 18:35:34 by acanterg         ###   ########.fr       */
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

int	print_error_cd(char *msg, char* dir)
{
	ft_putstr_fd("cd: ", 2);
	if (dir) {
		ft_putstr_fd(dir, 2);
		free(dir);
	}
	ft_putendl_fd(msg, 2);
	return (1);
}


int	ft_cd(int i)
{
	char	*dir;
	int		res_dir;

	if (ft_strcmp(get_ms()->blocks[i].argv[1], "-") == 0
		&& !get_env_value("OLDPWD"))
		return (print_error_cd(": OLDPWD not set", 0));
	dir = ft_strdup(get_dir(i));
	res_dir = is_valid_dir(dir);
	if (res_dir == 1)
		change_dir(dir);
	else if (res_dir == 2)
		return (print_error_cd(": Not a directory", dir));
	else
		return (print_error_cd(": No such file or directory", dir));
	free(dir);
	return (0);
}
