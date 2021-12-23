/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:52:11 by egomes            #+#    #+#             */
/*   Updated: 2021/12/23 04:23:25 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

/*
Funçoes da bin :
chmod dash df expr ksh ln mv pwd sh sync unlink bash cp	date
echo hostname launchctl ls	pax	rm sleep tcsh wait4path cat
csh	dd ed kill	link mkdir ps rmdir	stty test zsh
*/
int	bin(char **argv, int i)
{
	pid_t pid1;
	char *cmd;
	int status;
	int fd;

	cmd = ft_strjoin("/bin/", argv[0]);
	pid1 = fork();
	waitpid(pid1, &status,0);
	if (pid1 == 0)
	{
		if (argv[i - 1])
		{
			fd = open(argv[i], O_WRONLY);
			dup2(fd, 1);
			argv[i - 1] = NULL;
		}
		if (execve(cmd, argv, NULL) == -1)
			return (0);
	}
	return (1);
}