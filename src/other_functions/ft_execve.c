/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:22:49 by egomes            #+#    #+#             */
/*   Updated: 2022/01/06 15:02:35 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_execve(char **argv, int i, char *cmd)
{
	t_mini_shell *ms;
	pid_t pid1;
	int status;
	int fd;

	ms = get_ms();
	pid1 = fork();
	waitpid (pid1, &status,0);
	if (pid1 == 0)
	{
		if (ms->is_out_file)
		{
			if (ft_strcmp(argv[i - 1], OUT_FILE) == 0)
				fd = open(argv[i], O_WRONLY | O_TRUNC | O_CREAT, 0644);
			else
				fd = open(argv[i], O_WRONLY | O_APPEND | O_CREAT, 0644);
			dup2(fd, 1);
			argv[i - 1] = NULL;
			ms->is_out_file = 0;
		}
		if (execve(cmd, argv, NULL) == 0)
			return (1);
	}
	return (0);
}
