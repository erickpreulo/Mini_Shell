/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:18:55 by egomes            #+#    #+#             */
/*   Updated: 2022/01/03 12:37:47 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	select_cmd(char **command)
{
	int i;

	if (ft_strcmp(command[0], "exit") == 0)
		exit(0);
	if (ft_strcmp(command[0], "cd") == 0)
	{
		chdir(command[1]);
		return (0);
	}
	i = find_arrow(command);
	if (i != 0)
		touch(command[i]);
	if (ft_strcmp(command[0], "pwd") == 0)
		ft_execve(command, i, "/bin/pwd");
	else if (ft_strcmp(command[0], "ls") == 0)
		ft_execve(command, i, "/bin/ls");
	else if (ft_strcmp(command[0], "echo") == 0)
		ft_execve(command, i, "/bin/echo");
	else if (ft_strcmp(command[0], "export") == 0)
		ft_execve(command, i, "/usr/bin/export");
	else if (ft_strcmp(command[0], "unset") == 0)
		ft_execve(command, i, "/usr/bin/unset");
	else if (ft_strcmp(command[0], "env") == 0)
		ft_execve(command, i, "/usr/bin/env");
	return (0);
}

char    *get_line()
{
    char *line;

    line = NULL;
    if (line)
    {
        free(line);
        line = NULL;
    }
    line = readline("Cyber38@TM %> ");
    if (!line) {
        printf("exit\n");
        exit(0);
    }
	if (line)
        add_history(line);
    return (line);
}

void    sig_handler(int signum)
{
	(void)signum;
        rl_redisplay();
        rl_on_new_line();
        //rl_replace_line("", 0);
        printf("\n");
        rl_redisplay();
}

int main(void)
{
	//int r;
	char *line;
	char **command;

	signal(2, sig_handler);
    while(1)
    {
        line = get_line();
        if (line[0] != '\0')
		{
			command = ft_split(line, ' ');
            if (select_cmd(command))
				printf("%s not found\n", command[0]);
		}
    }

/* 	line = NULL;
	write(1, "Cyber38@TM % ", 14);
	while ((r = get_next_line(&line)) > 0)
	{
		command = ft_split(line, ' ');
		if (select_cmd(command))
		{
			printf("%s not found\n", command[0]);
		}
		free(line);
		write(1, "Cyber38@TM % ", 14);
	} */
	free(line);
}
