/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:08:44 by acanterg          #+#    #+#             */
/*   Updated: 2022/02/15 16:28:54 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	show_pwd()
{
	char	*pwd;

	pwd = get_current_dir();

	if (get_ms()->final_status)
		ft_putstr_fd("\033[0;31m", STDOUT_FILENO);
	else
		ft_putstr_fd("\033[0;32m", STDOUT_FILENO);
	ft_putstr_fd("➜  \033[0;36m", STDOUT_FILENO);
	ft_putstr_fd(pwd, STDOUT_FILENO);
	ft_putstr_fd("\033[0;35m % \033[0m", STDOUT_FILENO);
	free(pwd);
}

char	*get_line()
{
	char	*line;

	line = NULL;
	if (line)
	{
		free(line);
		line = NULL;
	}
	show_pwd();
	line = readline("\033[0;32mCyber38@TM \033[0;31m$> \033[0m");
	if (!line)
	{
		get_ms()->sig_exit = 1;
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		exit_safe();
	}
	if (line)
		add_history(line);
	return (line);
}