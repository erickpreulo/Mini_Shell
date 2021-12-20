#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char *env_variable = getenv("HOME");
	printf("Env_Variable:\n%s\n", env_variable);
	return (0);
}

//Eu consigo ver encontrar as pastas das funcoes do sistema.