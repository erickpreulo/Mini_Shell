/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:49:45 by egomes            #+#    #+#             */
/*   Updated: 2022/02/11 05:00:56 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_exit(int i)
{
	t_mini_shell *ms;
	char *arg;
	int j;
	ms = get_ms();
	
	if (!ms->blocks[i].first_of_group
		|| (ms->blocks[i].first_of_group && !ms->blocks[i].last_of_group))
		return (0);
	ft_putendl_fd("exit", 1);
	if (ms->blocks[i].argv[1] == 0)
		exit_safe();
	j = -1;
	arg = ms->blocks[i].argv[1];
	while (arg[++j])
		if (!ft_isdigit(arg[j]))
		{
			ft_putstr_fd("exit: ", 2);
			ft_putstr_fd(arg, 2);
			ft_putendl_fd(": numeric argument required", 2);
			ms->exit_num = 255;
			exit_safe();
		}
	ms->exit_num = ft_atoi(arg);
	exit_safe();
	return (0);
}
