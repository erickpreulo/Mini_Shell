/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:49:45 by egomes            #+#    #+#             */
/*   Updated: 2022/02/17 15:49:33 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	printf_err_num(t_mini_shell	*ms, char *arg)
{
	ft_putstr_fd("exit: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	ms->exit_num = 255;
	exit_safe();
}

bool	check_arg_nbr(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		if (!ft_isdigit(arg[i]))
			return (false);
	return (true);
}

int	ft_exit(int i)
{
	t_mini_shell	*ms;
	char			*arg;
	bool			arg_is_nbr;

	ms = get_ms();
	if (ms->size > 1)
		return (0);
	ft_putendl_fd("exit", 1);
	if (ms->blocks[i].argv[1] == 0)
		exit_safe();
	arg = ms->blocks[i].argv[1];
	arg_is_nbr = check_arg_nbr(arg);
	if (!arg_is_nbr)
		printf_err_num(ms, arg);
	if (ms->blocks[i].argv[2])
	{
		ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ms->exit_num = ft_atoi(arg);
	exit_safe();
	return (0);
}
