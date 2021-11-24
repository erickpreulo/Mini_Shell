#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int pid = fork();
	if (pid == -1)
	{
		return 1;
	}
	if (pid == 0)
	{
		int file = open("pingResults.txt", O_WRONLY | O_CREAT, 0777);
		if (file == -1)
		{
			return 2;
		}
		printf("The pingresult fd: %d\n", file);
		int file2 = dup2(file, STDOUT_FILENO);
		printf("The duplicate fd: %d\n", file2);
		close(file);
	}
}

// e´ uma opçao para redirecionar o standard output