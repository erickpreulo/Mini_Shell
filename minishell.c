/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:18:55 by egomes            #+#    #+#             */
/*   Updated: 2022/02/17 10:57:38 by acanterg         ###   ########.fr       */
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

int	main(int argc, char **argv, char **env)
{
	char	*line;

	if (argc > 1)	
		execve("/usr/bin/bash", argv, env);
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
