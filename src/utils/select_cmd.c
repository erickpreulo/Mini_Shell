/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:06:47 by egomes            #+#    #+#             */
/*   Updated: 2022/02/08 00:54:36 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	select_cmd(int i)
{
	t_mini_shell	*ms;

	ms = get_ms();
	ft_redirect(i);
	if (is_file(ms->blocks[i].type))
		return (0);
	if (ft_strcmp(ms->blocks[i].cmd, "exit") == 0)
		ft_exit();
	else if (ft_strcmp(ms->blocks[i].cmd, "cd") == 0)
		ft_cd(i);
	else if (ft_strcmp(ms->blocks[i].cmd, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(ms->blocks[i].cmd, "echo") == 0)
		ft_echo(i);
	else if (ft_strcmp(ms->blocks[i].cmd, "export") == 0)
		ft_export(i);
	else if (ft_strcmp(ms->blocks[i].cmd, "unset") == 0)
		ft_unset(i);
	else if (ft_strcmp(ms->blocks[i].cmd, "env") == 0)
		ft_env();
	else if (ms->blocks[i].path_cmd)
		ft_execve(i);
	else
	{
		printf("%s not found, bitch!\n", ms->blocks[i].cmd);
		ms->final_status = 127;
	}
	if (i > 0 && i < ms->size -1)
		ms->current_pipe += 1;
	return (0);
}
