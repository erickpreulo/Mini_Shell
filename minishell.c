/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:18:55 by egomes            #+#    #+#             */
/*   Updated: 2022/02/13 17:41:53 by acanterg         ###   ########.fr       */
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

char	*get_line(void)
{
	char	*line;

	line = NULL;
	if (line)
	{
		free(line);
		line = NULL;
	}
	line = readline("\033[0;32mCyber38@TM \033[0;31m%> \033[0m");
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

int	main(int argc, char **argv, char **env)
{
	char	*line;

	(void) argc;
	(void) argv;
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
}
