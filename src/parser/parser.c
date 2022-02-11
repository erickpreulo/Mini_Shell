/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:30:17 by egomes            #+#    #+#             */
/*   Updated: 2022/02/11 02:45:47 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	have_separator(char c, char bf, char aft)
{
	if (c == '|'
		|| (c == '>' && aft == '>')
		|| (c == '<' && aft == '<')
		|| (c == '>' && aft != '>' && bf != '>')
		|| (c == '<' && aft != '<' && bf != '<'))
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

bool check_valid_aspas(char *line)
{
	int i;
	char	aspas;

	// check aspas
	aspas = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\'' || line[i] == '\"')
		{
			aspas = line[i];
			i++;
		}
		while (aspas != 0 && line[i] != aspas && line[i] != '\0')
			i++;
		if (line[i] == '\0')
			break ;
		if (aspas)
		{
			aspas = 0;
			i++;
		}
		i++;
	}
	if (aspas)
	{
		printf("error on aspas, nigga\n");
		return (false);
	}
	return (true);
}

void jump_super_separator(char *str, int *i)
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

bool is_separator(char c)
{
	if (c == '|' || c == '>' || c== '<')
		return (true);
	return (false);
}

bool check_valid_filename(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		while (!is_separator(line[i]) && line[i] != '\0')
			i++;
		if (line[i] == '\0')
			break ;
		jump_super_separator(line, &i);
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0')
		{
			ft_putendl_fd("syntax error near unexpected token `newline'", 2);
			return (false);
		}
		if (is_separator(line[i]))
		{
			ft_putstr_fd("syntax error near unexpected token `", 2);
			ft_putchar_fd(line[i], 2);
			if (line[i+1] == line[i] && line[i+1] != '|')
				ft_putchar_fd(line[i + 1], 2);
			ft_putendl_fd("'", 2);
			return (false);
		}
		i++;
	}
	return (true);
}

void	parse(char *line)
{
	int		i;
	int		j;
	int		start;
	char	*str;
	char	aspas;

	aspas = 0;
	i = -1;
	j = 0;
	start = 0;
	if (!check_valid_aspas(line) || !check_valid_filename(line))
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
			break ;
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
	str = ft_substr(line, start, i);
	create_block(str);
	//print_blocks();
	ft_executor();
}
