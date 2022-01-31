/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:18:55 by egomes            #+#    #+#             */
/*   Updated: 2022/01/31 01:39:50 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

static void	start_struct(char **env)
{
	t_mini_shell *ms;
	int i;

	ms = get_ms();
	ms->env = malloc(sizeof(char *) * 200);
	i = 0;
	while(i < 200)
		ms->env[i++] = 0;
	i = 0;
	while (env[i])
	{
		ms->env[i] = ft_strdup(env[i]);
		i++;
	}
}

static void	reset_struct()
{
	t_mini_shell *ms;

	ms = get_ms();
	ms->size = 0;
	ms->group_size = 0;
	ms->current_pipe = 0;
}

t_mini_shell *get_ms()
{
	static t_mini_shell *ms;
	
	if (!ms)
		ms = malloc(sizeof(t_mini_shell));
	if (!ms)
		exit(0);
	return (ms);
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
        printf("exit error line\n");
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

	(void) argc;
	(void) argv;

	signal(2, sig_handler);
	start_struct(env);
    while(1)
    {
		reset_struct();
        line = get_line();
        if (line[0] != '\0')
			parse(line);
    }
	free(line);
}
