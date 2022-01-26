/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:01:08 by egomes            #+#    #+#             */
/*   Updated: 2022/01/20 04:24:24 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	print_blocks()
{
	int i;
	t_mini_shell *ms;

	ms = get_ms();

	i = 0;
	while (i < ms->size)
	{
		printf("\n=== BLOCK %d ===\n", i);
		printf("type:\t\t|%u|\n", ms->blocks[i].type);
		printf("str:\t\t|%s|\n", ms->blocks[i].str);
		int j = -1;
		while(ms->blocks[i].argv[++j] != 0)
			printf("argv [%d]:\t\t|%s|\n", j, ms->blocks[i].argv[j]);
		printf("cmd:\t\t|%s|\n", ms->blocks[i].cmd);
		printf("path_cmd:\t|%s|\n", ms->blocks[i].path_cmd);
		printf("group:\t\t|%d|\n", ms->blocks[i].group);
		printf("first_of_group:\t|%d|\n", ms->blocks[i].first_of_group);
		printf("last_of_group:\t|%d|\n", ms->blocks[i].last_of_group);
		printf("\n");
		i++;
	}
}
