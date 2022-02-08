/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:18:55 by egomes            #+#    #+#             */
/*   Updated: 2022/02/07 23:04:58 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

t_mini_shell *get_ms(void)
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
    line = readline("\033[0;32mCyber38@TM \033[0;31m%> \033[0m");
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
