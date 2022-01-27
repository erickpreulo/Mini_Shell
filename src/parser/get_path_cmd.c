/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:15:41 by acanterg          #+#    #+#             */
/*   Updated: 2022/01/27 11:19:55 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char *get_path_cmd (char *cmd)
{
	char *path_str = getenv("PATH");
	char **paths = ft_split(path_str, ':');
	char *concat1;
	char *concat2;

	while (*paths) 
	{
		concat1 = ft_strjoin(*paths, "/");
		concat2 = ft_strjoin(concat1, cmd);
		free(concat1);
		if (access(concat2, F_OK) == 0)
			return (concat2);
		paths++;
	}
	if (access(cmd, F_OK) == 0)
		return (cmd);
	return (0);
}
