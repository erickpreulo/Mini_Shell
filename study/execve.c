#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

/* esta funçao serve para executar um programa dentro de outro programa.

execve () executa o programa referido pelo nome do caminho . Esse
	faz com que o programa que está sendo executado pela chamada
	processo a ser substituído por um novo programa, com recém-inicializado
	empilhar, heap e segmentos de dados (inicializados e não inicializados).

	o nome do caminho deve ser um executável binário ou um script iniciando
	com uma linha do formulário.

	e´ como substituir o que esta´ rodando por outro programa.

*/

int	main(int ac, char **av)
{

	char cmd[] = "/bin/ls";

	char *argVec[] = {"ls", "-1", NULL};
	char *envVec[] = {NULL};

	printf("Start to execve call %s: \n", cmd);
	printf("===================================================\n");
	if (execve(cmd, argVec, envVec) == -1)
	{
		perror("error");
	}
	printf("erro final.");
	//envp = environment list.
	//execve(pathname, av, envp)
}