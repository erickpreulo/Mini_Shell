#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>

void func()
{
    printf("ola da func!!!\n");
}

int main() 
{
    pid_t pid1;
	char *cmd;

	cmd = "/bin/echo";
	int status = 0;
    printf("antes do fork!!\n");
	pid1 = fork();
    printf("depois do fork!!\n");
	waitpid(pid1, &status,0);
	if (pid1 == 0)
	{
		printf("estou no novo!!! getid=%d\n ", getpid());
        func();
	} else {
        printf("estou no velho!! getid=%d\n", getpid());
    }

	return (0);
}