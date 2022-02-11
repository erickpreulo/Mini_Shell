/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:28:50 by egomes            #+#    #+#             */
/*   Updated: 2022/02/11 07:14:24 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_echo(int i)
{
	t_mini_shell	*ms;
	char			**argv;

	ms = get_ms();
	if (!ms->blocks[i].argv[1])
	{
		ft_putendl_fd("", ms->fd_exit);
		return (0);
	}
	argv = ms->blocks[i].argv + 1;
	if (ft_strcmp(*argv, "-n") == 0)
		argv++;
	while (*argv)
	{
		ft_putstr_fd(*argv, ms->fd_exit);
		if (*(argv + 1))
			ft_putchar_fd(' ', ms->fd_exit);
		argv++;
	}
	if (ft_strcmp(ms->blocks[i].argv[1], "-n") != 0)
		ft_putchar_fd('\n', ms->fd_exit);
	return (0);
}
