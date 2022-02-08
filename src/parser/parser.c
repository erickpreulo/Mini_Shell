/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:30:17 by egomes            #+#    #+#             */
/*   Updated: 2022/02/04 17:02:06 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int		have_separator(char c, char bf, char aft)
{
	if (c == '|' || c == '<'
		|| (c == '>' && aft == '>')
		|| (c == '>' && aft != '>' && bf != '>'))
			return (1);
	return (0);
}

char	*take_off_quotes(char *line)
{
	int i;

	i = -1;;
	while (line[++i] != '\0')
		line[i] = line[i + 1];
	line[i - 2] = '\0';
	return (line);
}

void	parse(char *line)
{
	int i;
	int j;
	int start;
	char *str;
	char aspas;

	aspas = 0;
	i = -1;
	j = 0;
	start = 0;
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
		if (have_separator(line[i], line[i - 1], line[i + 1]))
		{
			str = ft_substr(line, start, i - start);
			create_block(str);
			start = i;
			j++;
		}
	}
	if (aspas)
	{
		printf("error on aspas, nigga\n");
		return;
	}
	str = ft_substr(line, start, i);
	create_block(str);
	//print_blocks();
	ft_executor();
}
