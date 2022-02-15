/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:36:16 by egomes            #+#    #+#             */
/*   Updated: 2022/02/15 21:25:35 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	redirect_input(int i)
{
	t_mini_shell *ms;

	ms = get_ms();

	// PADRÃO, FD_ENTER É O STDIN.
	//printf("Redirect fd_enter to STDIN_FILENO\n");
	ms->fd_enter = STDIN_FILENO;

	// SE FOR UM PIPE, FD_ENTER APONTA PARA O PROPRIO PIPE
	if (ms->blocks[i].type == T_PIPE) {
		//printf("Redirect fd_enter to ms->blocks[%d].pipe[PIPE_READ]\n", i);
		ms->fd_enter = ms->blocks[i].pipe[PIPE_READ];
	}
	// SE O LAST_OF_GROUP E EXISTIR UM FD_IN PARA O GRUPO, FD_ENTER APONTA PARA O FD_IN.
	if (ms->blocks[i].last_of_group && ms->fd_in[ms->blocks[i].group]) {
		//printf("Redirect fd_enter to ms->fd_in[ms->blocks[%d].group]\n", i);
		ms->fd_enter = ms->fd_in[ms->blocks[i].group];
	}
}

void	redirect_output(int i)
{
	t_mini_shell *ms;

	ms = get_ms();

	// PADRÃO, FD_EXIT É O STDOUT.
	ms->fd_exit = STDOUT_FILENO;
	//printf("Redirect fd_exit to STDOUT_FILENO\n");

	// SE NÃO FOR O LAST OF GROUP, ESCREVE NO PROXIMO PIPE
	if (!ms->blocks[i].last_of_group) {
		//printf("Redirect fd_exit to ms->blocks[%d].pipe[PIPE_WRITE])\n", i + 1);
		ms->fd_exit = ms->blocks[i + 1].pipe[PIPE_WRITE];
	}

	// SE ELE FOR O ULTIMO DO GRUPO E TIVER UM FD_OUT, FD_EXIT APONTA PARA O FD_OUT
	if (ms->blocks[i].last_of_group && ms->fd_out[ms->blocks[i].group]) {
		//printf("Redirect fd_exit to ms->fd_out[ms->blocks[%d].group]\n", i);
		ms->fd_exit = ms->fd_out[ms->blocks[i].group];
	}
	
	// SE ELE FOR O ULTIMO DO GRUPO E NÃO TIVER FD_OUT, MAS TEM OUTRO PIPE NA FRENTE, USA O PROXIMO PIPE.
	else if (ms->blocks[i].last_of_group && i < ms->size - 1) {
		//printf("Redirect fd_exit to ms->blocks[%d].pipe[PIPE_WRITE])\n", i + 1);
		ms->fd_exit = ms->blocks[i + 1].pipe[PIPE_WRITE];
	}
}
