/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:47:51 by egomes            #+#    #+#             */
/*   Updated: 2022/01/14 11:28:07 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int		ft_executor()
{
	int i;
	t_mini_shell *ms;

	i = 0;
	ms = get_ms();
	while (i < ms->size)
	{
		ft_execve(i);
		// if (ms->blocks[i + 1].type == T_PIPE)
		// 	ft_exec_pipe(i, size);
		i++;
	}
	return (0);
}