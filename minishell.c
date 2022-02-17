/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:18:55 by egomes            #+#    #+#             */
/*   Updated: 2022/02/17 11:08:27 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

t_mini_shell	*get_ms(void)
{
	static t_mini_shell	*ms;

	if (!ms)
		ms = malloc(sizeof(t_mini_shell));
	if (!ms)
		exit(0);
	return (ms);
}

void	check_script_mode(int argc, char **argv, char **env)
{
	if (argc == 1)
		return;

	execve("/usr/bin/bash", argv, env);
	ft_putendl_fd("Error in non-interative mode execution", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **env)
{
	char	*line;

	check_script_mode(argc, argv, env);
	start_signal();
	get_env_list(env);
	while (1)
	{
		reset_struct();
		line = get_line();
		if (line[0] != '\0')
			parse(line);
		free(line);
		clean_up();
	}
	free(line);
	return (0);
}
