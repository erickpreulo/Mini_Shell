/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:30:17 by egomes            #+#    #+#             */
/*   Updated: 2022/01/20 12:21:10 by egomes           ###   ########.fr       */
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

void	parse(char *line)
{
	int i;
	int j;
	int start;
	char *str;
	t_mini_shell *ms;

	ms = get_ms();
	i = -1;
	j = 0;
	start = 0;
	while (line[++i] != '\0')
	{
		if (have_separator(line[i], line[i - 1], line[i + 1]))
		{
			str = ft_substr(line, start, i - start);
			create_block(str);
			//free(str);
			start = i;
			j++;
		}
	}
	str = ft_substr(line, start, i);
	create_block(str);
	//free(str);
	ft_executor();
}
