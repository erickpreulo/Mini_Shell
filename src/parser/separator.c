/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 03:53:59 by egomes            #+#    #+#             */
/*   Updated: 2022/02/11 06:34:32 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	jump_super_separator(char *str, int *i)
{
	if (str[*i] == '|')
	{
		(*i)++;
		return ;
	}
	if (str[*i] == '>' || str[*i] == '<')
	{
		(*i)++;
	}
	if (str[*i] != '\0' && str[*i] == str[(*i) - 1])
	{
		(*i)++;
	}
}

bool	is_separator(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (true);
	return (false);
}

void	ft_print(char *line, int i)
{
	ft_putstr_fd("syntax error near unexpected token `", 2);
	ft_putchar_fd(line[i], 2);
	if (line[i + 1] == line[i] && line[i + 1] != '|')
		ft_putchar_fd(line[i + 1], 2);
	ft_putendl_fd("'", 2);
}

bool inside_aspas(char *line, int i)
{
	int j = 0;
	int count;

	count = 0;
	j = 0;
	while (j < i)
	{
		if (line[j] == '\"')
			count++;
		j++;
	}
	if (count % 2 == 1)
		return (true);
	count = 0;
	j = 0;
	while (j < i)
	{
		if (line[j] == '\'')
			count++;
		j++;
	}
	if (count % 2 == 1)
		return (true);
		
	return (false);
}

bool	check_valid_filename(char *line)
{
	int	i;

	i = -1;
	while (line[++i] != '\0')
	{
		while (!is_separator(line[i]) && line[i] != '\0')
			i++;
		if (line[i] == '\0')
			break ;
		jump_super_separator(line, &i);
		while (line[i] == ' ')
			i++;
		if (inside_aspas(line, i))
			continue;
		if (line[i] == '\0')
		{
			ft_putendl_fd("syntax error near unexpected token `newline'", 2);
			return (false);
		}
		if (is_separator(line[i]))
		{
			ft_print(line, i);
			return (false);
		}
	}
	return (true);
}
