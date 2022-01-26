/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:18:55 by egomes            #+#    #+#             */
/*   Updated: 2022/01/20 16:02:32 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

static void	start_struct(char **env)
{
	t_mini_shell *ms;

	ms = get_ms();
	ms->size = 0;
	ms->group_size = 0;
	ms->env = env;
	ms->current_pipe = 0;
	ms->contact = malloc(30 * sizeof(char *));
}

t_mini_shell *get_ms()
{
	static t_mini_shell *ms;
	
	if (!ms)
		ms = malloc(sizeof(ms));
	if (!ms)
		exit(0);
	return (ms);
}

int	select_cmd(char **command)
{
	if (ft_strcmp(command[0], "exit") == 0)
	{
		printf("exit\n");
		exit(0);
	}
	if (ft_strcmp(command[0], "cd") == 0)
	{
		chdir(command[1]);
		return (0);
	}
	if (ft_strcmp(command[0], "pwd") == 0)
		ft_pwd(command);
	else if (ft_strcmp(command[0], "echo") == 0)
		ft_echo(command);
	else if (ft_strcmp(command[0], "export") == 0)
		ft_export(command);
	else if (ft_strcmp(command[0], "unset") == 0)
		ft_unset(command);
	else if (ft_strcmp(command[0], "env") == 0)
		ft_env(command);
	else
		return (0);//ft_access(command);
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

int main(int argc, char** argv, char **env)
{
	char *line;
	char **command;

	(void) argc;
	(void) argv;

	signal(2, sig_handler);
    while(1)
    {
		start_struct(env);
        line = get_line();
        if (line[0] != '\0')
		{
			command = ft_split(line, ' ');
			parse(line);
            if (select_cmd(command))
				printf("%s not found\n", command[0]);
		}
    }
	free(line);
}
