/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:16:14 by egomes            #+#    #+#             */
/*   Updated: 2022/02/09 19:14:05 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "headers/mini_shell.h"

int main(int argc, char **argv)
{
	
	int fd[2][2];

	int pid1;
	int pid2;
	int pid3;

	pipe(fd[0]);

	pid1 = fork();
	if (pid1 == 0)
	{
		printf("PID 1 - child...\n");
		dup2(fd[0][1], 1);
		char *argvv[] = { "ls", NULL };
		execve("/bin/ls", argvv, NULL);
	}
	
	waitpid(pid1, NULL, 0);
	close(fd[0][1]);
	printf("pid1 - parent - waiting...\n");

	pipe(fd[1]);
	pid2 = fork();
	if (pid2 == 0)
	{
		printf("PID 2 - child\n");
		dup2(fd[0][0], 0);
		dup2(fd[1][1], 1);
		char *argvv[] = {"grep", "a" , NULL};
		execve("/usr/bin/grep", argvv, NULL);
	}
	waitpid(pid2, NULL, 0);
	//close(fd[0][0]);
	close(fd[1][1]);
	printf("pid2 - parent - waiting...\n");

	pid3 = fork();
	if (pid3 == 0)
	{
		printf("PID 3 - child\n");
		dup2(fd[1][0], 0);
		char *argvv[] = {"grep", "h" , NULL};
		execve("/usr/bin/grep", argvv, NULL);
	}
	waitpid(pid3, NULL, 0);
	//close(fd[1][0]);
	printf("pid3 - parent - waiting...\n");


	printf("End...\n");


	return(0);
}