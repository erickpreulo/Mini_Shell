/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:30:17 by egomes            #+#    #+#             */
/*   Updated: 2022/02/17 15:23:04 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

bool	have_separator(char *line, int i)
{
	if (i == 0)
	{
		if (line[i] == '|'
			|| (line[i] == '>' && line[i + 1] == '>')
			|| (line[i] == '<' && line[i + 1] == '<'))
			return (true);
		return (false);
	}
	if (line[i] == '|'
		|| (line[i] == '>' && line[i + 1] == '>')
		|| (line[i] == '<' && line[i + 1] == '<')
		|| (line[i] == '>' && line[i + 1] != '>' && line[i - 1] != '>')
		|| (line[i] == '<' && line[i + 1] != '<' && line[i - 1] != '<'))
		return (true);
	return (false);
}

bool	check_aspas(char *line)
{
	const int	size = ft_strlen(line);
	int			i;
	char		aspas;

	aspas = 0;
	i = -1;
	while (++i < size)
	{
		while (line[i] != '\0' && line[i] != '\'' && line[i] != '\"')
			i++;
		if (i >= size)
			break ;
		aspas = line[i++];
		while (i < size && line[i] != aspas)
			i++;
		if (i >= size)
			break ;
		aspas = '\0';
	}
	if (aspas)
	{
		ft_putendl_fd("Wrong quotes!", STDERR_FILENO);
		return (false);
	}
	return (true);
}

bool	check_empty(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\t' && *line != '\0')
			return (true);
		line++;
	}
	return (false);
}

void	parse_2(char *aspas, char *line, t_gamb *gamb)
{
	if (*aspas)
	{
		*aspas = 0;
		gamb->i++;
	}
	if (have_separator(line, gamb->i))
	{
		create_block(ft_substr(line, gamb->start, gamb->i - gamb->start));
		gamb->start = gamb->i;
	}
}

void	parse(char *line)
{
	const int	size = ft_strlen(line);
	t_gamb		gamb;
	char		aspas;

	aspas = 0;
	gamb.i = 0;
	gamb.start = 0;
	if (!check_aspas(line) || !check_valid_file(line) || !check_empty(line))
		return ;
	while (is_separator(line[gamb.i]))
		gamb.i++;
	while (gamb.i < size)
	{		
		if (line[gamb.i] == '\'' || line[gamb.i] == '\"')
			aspas = line[gamb.i++];
		while (aspas != 0 && line[gamb.i] != aspas && line[gamb.i] != '\0')
			gamb.i++;
		if (gamb.i >= size)
			break ;
		parse_2(&aspas, line, &gamb);
		gamb.i++;
	}
	create_block(ft_substr(line, gamb.start, gamb.i));
	ft_executor();
}
