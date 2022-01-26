/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:57:39 by acanterg          #+#    #+#             */
/*   Updated: 2022/01/20 13:35:33 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int open_file_output(char *file_name)
{
	int fd;

	fd = open(file_name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		printf("error on trying to open file output: %s\n", file_name);
	return (fd);
}

int open_file_append(char *file_name)
{
	int fd;

	fd = open(file_name, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
		printf("error on trying to open file append: %s\n", file_name);
	return (fd);
}

int open_file_input(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		printf("error on trying to open file input: %s\n", file_name);
	return (fd);
}