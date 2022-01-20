/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:30:47 by egomes            #+#    #+#             */
/*   Updated: 2022/01/20 15:46:21 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

type_sep get_type(char *str)
{
	if (str[0] == '|' && str[1] == ' ')
		return (T_PIPE);
	if (str[0] == '<' && str[1] == ' ')
		return (T_FILE_IN);
	if (str[0] == '>' && str[1] == ' ')
		return (T_FILE_OUT);
	if (str[0] == '>' && str[1] == '>' && str[2] == ' ')
		return (T_FILE_APPEND);
	return (T_CMD);
}

bool is_file(type_sep type)
{
	if (type == T_FILE_APPEND || type == T_FILE_OUT || type == T_FILE_IN)
		return (true);
	return (false);
}