/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:30:17 by egomes            #+#    #+#             */
/*   Updated: 2022/02/11 06:14:38 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	have_separator(char *line, int i)
{
	if (i == 0)
	{
		if (line[i] == '|'
			|| (line[i] == '>' && line[i + 1] == '>')
			|| (line[i] == '<' && line[i + 1] == '<'))
			return (1);
		return (0);
	}
	if (line[i] == '|'
		|| (line[i] == '>' && line[i + 1] == '>')
		|| (line[i] == '<' && line[i + 1] == '<')
		|| (line[i] == '>' && line[i + 1] != '>' && line[i - 1] != '>')
		|| (line[i] == '<' && line[i + 1] != '<' && line[i - 1] != '<'))
		return (1);
	return (0);
}

char	*take_off_quotes(char *line)
{
	int	i;

	i = -1;
	while (line[++i] != '\0')
		line[i] = line[i + 1];
	line[i - 2] = '\0';
	return (line);
}

bool	check_valid_aspas(char *line)
{
	int		i;
	char	aspas;

	aspas = 0;
	i = 0;
	while (line[i] != '\0')
	{
		while (line[i] != '\0' && line[i] != '\'' && line[i] != '\"')
			i++;
		if (line[i] == '\0')
			break;
		aspas = line[i];
		i++;
		while (line[i] != '\0' && line[i] != aspas)
			i++;
		if (line[i] == '\0')
			break;
		aspas = '\0';
		i++;
	}
	if (aspas)
	{
		ft_putendl_fd("Wrong quotes!", 2);
		return (false);
	}
	return (true);
}

bool	check_empty(char *line)
{
	while(*line)
	{
		if (*line != ' ' && *line != '\t' && *line != '\0')
			return (true);
		line++;
	}
	return (false);
}

void	parse(char *line)
{
	int		i;
	int		start;
	char	*str;
	char	aspas;

	aspas = 0;
	i = -1;
	start = 0;
	if (!check_valid_aspas(line) || !check_valid_filename(line) || !check_empty(line))
		return ;
	while (line[++i] != '\0')
	{		
		if (line[i] == '\'' || line[i] == '\"')
		{
			aspas = line[i];
			i++;
		}
		while (aspas != 0 && line[i] != aspas && line[i] != '\0')
			i++;
		if (line[i] == '\0')
			break;
		if (aspas)
		{
			aspas = 0;
			i++;
		}
		if (have_separator(line, i))
		{
			str = ft_substr(line, start, i - start);
			create_block(str);
			start = i;
		}
	}
	str = ft_substr(line, start, i);
	create_block(str);
	ft_executor();
}
