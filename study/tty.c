#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>

#define MAX 256
#define DEV "/dev/tty"

char *myttyname(int fd)
{
	struct stat stin, stdev;
	DIR *dp;
	struct dirent *d;
	static char path[MAX];
	
	if (fstat(fd, &stin) == -1)
		return NULL;
	
	if (!S_ISCHR(stin.st_mode))
	{
		errno = ENOTTY;
		return NULL;
	}

	if ((dp = opendir(DEV)) == NULL)
		return NULL;
	
	while ((d = readdir(dp)) != NULL)
	{
		if (snprintf(path, sizeof path, "%s/%s", DEV, d->d_name) < sizeof path)
		{
			if (stat(path, &stdev) == 0 && stdev.st_dev == stin.st_dev && stdev.st_ino == stin.st_ino)
				break;
		}
		closedir (dp);
		if (d == NULL)
			return NULL;
		return path;
	}
}

int		main(void)
{
	int i;
	
	i = 0;
	while (i < 3)
	{
		char *p;
		p = myttyname(i);
		printf("ttyname(%d) = %s\n", i, (p == NULL)? "null" : p);
		i++;
	}
	//printf("res = %d\n", isatty(0));
	return (0);
}

// The isatty() function tests whether fd is an open file descripto referring to a terminal.

