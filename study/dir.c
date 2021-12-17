#include <stdio.h>
#include <string.h>
#include <dirent.h>

// Assim eu verifico todos os arquivos que estao na pasta. 
int		main(int argc, char **argv)
{
	DIR* dir = opendir(".");
	if (dir == NULL)
	{
		return 1;
	}

	struct dirent* entity;
	while(entity != NULL)
	{
		printf("%hhd %s\n", entity->d_type, entity->d_name);
		entity = readdir(dir);
	}
	closedir(dir);
	return 0;
}
