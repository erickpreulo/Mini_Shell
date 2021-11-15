/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:18:55 by egomes            #+#    #+#             */
/*   Updated: 2021/11/15 11:36:38 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int main(void)
{
	int r;
	char *line;
	
	line = NULL;
	while ((r = get_next_line(&line)) > 0)
	{
		//printf("Entrou no programa essa naba: %s\n", line);
		if (line[0] == 'l' && line[1] == 's')
			printf("mostra todas as infos\n");
		else 
			printf("%s not found\n%c\n", line, line[0]);
		free(line);
	}
	free(line);
}
