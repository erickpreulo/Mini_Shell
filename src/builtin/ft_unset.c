/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:30:12 by egomes            #+#    #+#             */
/*   Updated: 2022/02/02 07:57:22 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	*del(void *str)
{
	free(str);
	return (0);
}

int	ft_unset(int i)
{
	t_mini_shell *ms;
	t_list *curr;
	t_list *prev;
	char *var;
	int size;

	ms = get_ms();
	curr = *(ms->lst_env);
	// PEGA O NOME DA VARIAVEL QUE TEM QUE FAZER UNSET
	// ARGV[1] pq seria tipo unset "erick", então erick é a variavel
	if (ms->blocks[i].argv[1] != 0)
		var = ms->blocks[i].argv[1];
	else
	{
		printf("Unset what nigga???\n");
		return(0);
	}
	size = ft_strlen(var);
	prev = curr;
	if (ft_strncmp((char *)prev->content, var, size) == 0)
		printf("PRIMEIRO");
	prev = prev->next;
	while (prev)
	{
		if (ft_strncmp((char *)prev->content, var, size) == 0)
		{
			printf("LINE PREV= %s\n", (char *)prev->content);
			printf("LINE CURR = %s\n", (char *)curr->content);
			printf("PASSOU!!\n");
			curr = prev->next;
			printf("LINE CURR AFT= %s\n", (char *)curr->content);
			//ft_lstdelone(curr, del(curr->content));
		}
		else
			curr = curr->next;
		prev = prev->next;
	}
	while (curr)
	{
		ft_putendl_fd((char *)curr->content, ms->fd_exit);
		curr = curr->next;
	}
	//FAZER WHILE NA LISTA CURR, CURR->NEXT, ETC. E IR FAZENDO STRCMP ATÉ ACHAR


	// SE ACHAR, FAZER O ITEM DA LISTA ANTERIOR APONTAR PARA O PROX. PARA "REMOVER"


	// DICA 1: TEM QUE SEMPRE MANDAR O PONTEIRO DO ANTERIOR
	// ALGO TIPO: PRO ATUAL: t_list *curr E PRO PASSADO: t_list *prev

	// DICA 2: REMOVER O PRIMEIRO É DIFERENTE POR DOIS MOTIVOS:
	// 1. NÃO TEM t_list *prev, PQ É O PRIMEIRO KKKK
	// 2. O PRIMEIRO TEM QUE MUDAR TAMBEM O ms->lst_env, QUE APONTA PRO PRIMEIRO

	printf("unset not implemented yet, noob\n");
	
	return (0);
}
