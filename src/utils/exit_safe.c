/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_safe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 03:32:37 by acanterg          #+#    #+#             */
/*   Updated: 2022/02/16 19:32:23 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	exit_safe(void)
{
	t_mini_shell	*ms;

	ms = get_ms();
	free_lst_env();
	clean_up();
	if (ms->final_status)
		exit(ms->final_status);
	exit(ms->exit_num);
}
