#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int	main(int ac, char **av)
{
	printf("%s\n", strerror(0) );
	printf("%s\n", strerror(1) );
	printf("%s\n", strerror(2) );
	printf("%s\n", strerror(3) );
	printf("%s\n", strerror(4) );
	printf("%s\n", strerror(5) );
	printf("%s\n", strerror(6) );
	printf("%s\n", strerror(7) );
	perror("errou idiota");
	printf("%s\n", strerror(8) );

	// nao percebi muito sobre o perror
	// strerror : sao varias mensagens de erros ja preparadas!
}