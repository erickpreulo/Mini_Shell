/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:15:41 by acanterg          #+#    #+#             */
/*   Updated: 2022/02/13 17:17:43 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*free_paths(char **paths, char *str_to_return)
{
	int	i;

	if (!paths)
		return (str_to_return);
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths[i]);
	free(paths);
	return (str_to_return);
}

char	*get_path_cmd(char *cmd)
{
	char	*path_str;
	char	**paths;
	char	*concat1;
	char	*concat2;
	int		i;

	path_str = get_env_value("PATH");
	if (!path_str)
		return (0);
	paths = ft_split(path_str, ':');
	if (!paths || paths[0] == 0)
		return (0);
	i = -1;
	while (paths[++i])
	{
		concat1 = ft_strjoin(paths[i], "/");
		concat2 = ft_strjoin(concat1, cmd);
		free(concat1);
		if (access(concat2, F_OK) == 0)
			return (free_paths(paths, concat2));
		free(concat2);
	}
	if (access(cmd, F_OK) == 0)
		return (free_paths(paths, ft_strdup(cmd)));
	return (free_paths(paths, 0));
}
