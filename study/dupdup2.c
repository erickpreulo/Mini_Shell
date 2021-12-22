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
/* 	int pid = fork();
	if (pid == -1)
	{
		return 1;
	}
	if (pid == 0)
	{ */

	char *c;
	int file2;

	int file = open("pingResults.txt", O_RDONLY);

	read(file, &c, 1);
	printf("char from file1: %s\n", c);
	read(file, &c, 1);
	printf("char from file1 again: %c\n", c);

	dup2(file, file2);

	read(file2, &c, 1);
	printf("char from file2: %c\n", c);



	return (0);

/* 		if (file == -1)
		{
			return 2;
		}
		printf("The pingresult fd: %d\n", file);
		dup2(file, STDOUT_FILENO);
		printf("The duplicate fd: %d\n", file2);
		close(file); */


/* 	} */
}

// e´ uma opçao para redirecionar o standard output