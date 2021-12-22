#include "mini_shell.h"

int	ls(char **argv)
{
	//pid_t childpid = fork();

	char cmd[] = "/bin/ls";
	char **argVec = argv; //argv[0] = ls  | argv[1] = -la | argv[2] = null
	char *envVec[] = {NULL};
	fork();
	execve(cmd, argVec, envVec);
/* 	if (execve(cmd, argVec, envVec) == -1)
	{
		perror("error");
		return (1);
	}
	printf("erro final."); */
	return (0);
}