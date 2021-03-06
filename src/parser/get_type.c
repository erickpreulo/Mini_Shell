/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:30:47 by egomes            #+#    #+#             */
/*   Updated: 2022/02/17 15:26:04 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

t_type_sep	get_type(char *str)
{
	if (str[0] == '|' && (str[1] == ' ' || str[1] == '\0'))
		return (T_PIPE);
	if (str[0] == '<' && (str[1] == ' ' || str[1] == '\0'))
		return (T_FILE_IN);
	if (str[0] == '>' && (str[1] == ' ' || str[1] == '\0'))
		return (T_FILE_OUT);
	if (str[0] == '>' && str[1] == '>' && (str[2] == ' ' || str[2] == '\0'))
		return (T_FILE_APPEND);
	if (str[0] == '<' && str[1] == '<' && (str[2] == ' ' || str[2] == '\0'))
		return (T_FILE_DELIMITER);
	return (T_FIRST);
}

bool	is_file(t_type_sep type)
{
	if (type == T_FILE_APPEND || type == T_FILE_OUT
		|| type == T_FILE_IN || type == T_FILE_DELIMITER)
		return (true);
	return (false);
}

bool	is_separator(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (true);
	return (false);
}

void	check_old_fd(int fd_old)
{
	if (fd_old > 0)
		close(fd_old);
}
