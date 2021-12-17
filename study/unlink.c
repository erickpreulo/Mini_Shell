#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int	main(void)
{
	int ret;

	//ret = mkdir("teste_one", S_IRUSR | S_IRGRP | S_IROTH | S_IXUSR | S_IXOTH);

	ret = link("teste_one", "teste_two");

	//ret = unlink("teste_two");

	return (0);
}

//linkar uma pasta em outra. Provavelmente para linkar a pasta bin. Obs: so´ temos autorizaçao para usar o unlink.