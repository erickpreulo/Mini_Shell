/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:54:07 by acanterg          #+#    #+#             */
/*   Updated: 2022/01/14 11:21:35 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	take_block(char *str, int i)
{
	t_mini_shell *ms;
	
	ms = get_ms();

	ms->blocks[i].is_first = 0;
	ms->blocks[i].is_last = 0;
	ms->blocks[i].type = get_type(str);
	ms->blocks[i].str = get_clean_str(str);
	ms->blocks[i].argv = get_argv(ms->blocks[i].str);
	ms->blocks[i].cmd = ms->blocks[i].argv[0];
	ms->blocks[i].path_cmd = get_path_cmd(ms->blocks[i].cmd);
	if (i == 0) {
		ms->blocks[i].is_first = 1;
		ms->blocks[i].is_last = 1;
	} else {
		ms->blocks[i].is_last = 1;
		ms->blocks[i - 1].is_last = 0;
	}

	printf("\ntype    [%d]   : |%u|\n", i, ms->blocks[i].type);
	printf("str     [%d]   : |%s|\n", i, ms->blocks[i].str);
	int j = -1;
	while(ms->blocks[i].argv[++j] != 0)
		printf("argv[%d] [%d]   : |%s|\n",j, i, ms->blocks[i].argv[j]);
	printf("cmd     [%d]   : |%s|\n", i, ms->blocks[i].cmd);
	printf("path_cmd[%d]   : |%s|\n", i, ms->blocks[i].path_cmd);
	return (i);
}
