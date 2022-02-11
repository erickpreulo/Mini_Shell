/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:57:39 by acanterg          #+#    #+#             */
/*   Updated: 2022/02/11 01:54:49 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void check_old_fd(int fd_old)
{
	if (fd_old > 0)
		close(fd_old);
}

int	open_file_output(char *file_name, int group)
{
	int	fd;

	check_old_fd(get_ms()->fd_out[group]);
	fd = open(file_name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
	{
		printf("%s: No such file or directory\n", file_name);
		return (-1);
	}
	return (fd);
}

int	open_file_append(char *file_name, int group)
{
	int	fd;

	check_old_fd(get_ms()->fd_out[group]);
	fd = open(file_name, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
	{
		printf("%s: No such file or directory\n", file_name);
		return (-1);
	}
	return (fd);
}

int	open_file_input(char *file_name, int group)
{
	int	fd;

	check_old_fd(get_ms()->fd_in[group]);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("%s: No such file or directory\n", file_name);
		return (-1);
	}
	return (fd);
}

int	open_file_delimiter(char *file_name, char *delimiter, int group)
{
	int	fd;
	char *line = 0;
	int r;

	fd = open(".temp", O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
	{
		printf("%s: No such file or directory\n", file_name);
		return (-1);
	}
	ft_putstr_fd("> ", STDOUT_FILENO);
	while ((r = get_next_line(&line)))
	{
		if (ft_strcmp(line, delimiter) == 0)
			break;
		ft_putstr_fd("> ", STDOUT_FILENO);
		ft_putstr_fd(line, fd);
		ft_putchar_fd('\n', fd);
		free(line);
	}
	free(line);
	close(fd);
	return (open_file_input(".temp", group));
}