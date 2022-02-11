/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:30:17 by egomes            #+#    #+#             */
/*   Updated: 2022/02/11 07:43:18 by egomes           ###   ########.fr       */
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

bool	check_aspas(char *line)
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
			break ;
		aspas = line[i++];
		while (line[i] != '\0' && line[i] != aspas)
			i++;
		if (line[i] == '\0')
			break ;
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
	t_gamb	gamb;
	char	aspas;

	aspas = 0;
	gamb.i = -1;
	gamb.start = 0;
	if (!check_aspas(line) || !check_valid_file(line) || !check_empty(line))
		return ;
	while (line[++gamb.i] != '\0')
	{		
		if (line[gamb.i] == '\'' || line[gamb.i] == '\"')
			aspas = line[gamb.i++];
		while (aspas != 0 && line[gamb.i] != aspas && line[gamb.i] != '\0')
			gamb.i++;
		if (line[gamb.i] == '\0')
			break ;
		parse_2(&aspas, line, &gamb);
	}
	create_block(ft_substr(line, gamb.start, gamb.i));
	ft_executor();
}
