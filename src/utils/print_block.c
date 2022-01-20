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

void	print_block(int i)
{
	t_mini_shell *ms;

	ms = get_ms();
	printf("\ntype  [%d]  [%d]   : |%u|\n", i, ms->i, ms->blocks[ms->i][i].type);
	printf("str   [%d]  [%d]   : |%s|\n", i, ms->i, ms->blocks[ms->i][i].str);
	int j = -1;
	while(ms->blocks[ms->i][i].argv[++j] != 0)
		printf("argv[%d] [%d] [%d]   : |%s|\n",j, i, ms->i, ms->blocks[ms->i][i].argv[j]);
	printf("cmd   [%d]  [%d]   : |%s|\n", i, ms->i, ms->blocks[ms->i][i].cmd);
	printf("path_cmd [%d] [%d]   : |%s|\n", i, ms->i, ms->blocks[ms->i][i].path_cmd);
}
