/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:54:07 by acanterg          #+#    #+#             */
/*   Updated: 2022/01/20 16:12:01 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void adjust_group(int i, t_mini_shell *ms)
{
	// CASO O PRIMEIRO NÃO SEJA UM REDIRECT / FILE
	if (i == 0 && !is_file(ms->blocks[i].type))
		ms->blocks[i].first_of_group = true;

	// CASO SEJA UM PIPE DEPOIS DE UM ARQUIVO, SOBE O NUMERO DO GRUPO E MARCA COMO PRIMEIRO!
	if (i > 0 && ms->blocks[i].type == T_PIPE && is_file(ms->blocks[i - 1].type))
	{
		ms->blocks[i].first_of_group = true;
		ms->group_size += 1;
	}

	if (is_file(ms->blocks[i].type)) {
		ms->blocks[i].last_of_group = false;
	}

	if (i > 0 && ms->blocks[i].type == T_PIPE && !is_file(ms->blocks[i - 1].type)) {
		ms->blocks[i - 1].last_of_group = false;
	}

	// DÁ O NUMERO DO GRUPO PRO BLOCO
	ms->blocks[i].group = ms->group_size;
}

void	create_block(char *str)
{
	t_mini_shell *ms;
	int i;

	ms = get_ms();
	i = ms->size;

	ms->blocks[i].first_of_group = false; 
	ms->blocks[i].last_of_group = true; 

	// PEGA O TIPO DO BLOCK
	ms->blocks[i].type = get_type(str);

	// LIMPA A STR
	ms->blocks[i].str = get_clean_str(str);

	// ABRE O ARQUIVO E COLOCA NA POSIÇÃO CORRETA.
	if (ms->blocks[i].type == T_FILE_IN)
		ms->fd_in[ms->group_size] = open_file_input(ms->blocks[i].str);
	if (ms->blocks[i].type == T_FILE_OUT)
		ms->fd_out[ms->group_size] = open_file_output(ms->blocks[i].str);
	if (ms->blocks[i].type == T_FILE_APPEND)
		ms->fd_out[ms->group_size] = open_file_append(ms->blocks[i].str);

	// PEGA AS INFORMACOES DE ARGV, CMD E PATH_CMD
	ms->blocks[i].argv = get_argv(ms->blocks[i].str);
	ms->blocks[i].cmd = ms->blocks[i].argv[0];
	ms->blocks[i].path_cmd = get_path_cmd(ms->blocks[i].cmd);

	adjust_group(i, ms);
	
	// ++ PARA CONTAR OS BLOCOS
	ms->size++;

	// if (ms->blocks[i].type == T_FILE_IN
	// 	|| ms->blocks[i].type == T_FILE_OUT
	// 	|| ms->blocks[i].type == T_FILE_APPEND)
	// 	ms->size--;

}


	// if (is_file(ms->blocks[i].type))
	// 		ms->is_pipe = 1;
	// if (ms->blocks[i].type == T_PIPE && ms->is_pipe)
	// {
	// 	printf("\nAQUIIII!!!!\n");
	// 	ms->i++;
	// 	ms->size = 0;
	// 	i = ms->size;
	// 	ms->is_pipe = 0;
	// }
	