/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:55:09 by acanterg          #+#    #+#             */
/*   Updated: 2022/02/13 17:34:08 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	get_argv_cont(char *str, char **arr, t_gamb *gamb, int *start)
{
	char	aspas;

	if (str[gamb->i] == '\"' || str[gamb->i] == '\'')
	{
		aspas = str[gamb->i];
		(gamb->i)++;
		*start = gamb->i;
		while (str[gamb->i] != aspas)
			(gamb->i)++;
		if (aspas == '\"')
			arr[(gamb->x)++] = expand_env(ft_substr(str,
						*start, gamb->i - *start));
		else
			arr[(gamb->x)++] = ft_substr(str, *start, gamb->i - *start);
		(gamb->i)++;
	}
	else
	{
		*start = gamb->i;
		while (str[gamb->i] != ' ' && str[gamb->i] != '\"'
			&& str[gamb->i] != '\'' && str[gamb->i] != '\0')
			(gamb->i)++;
		arr[(gamb->x)++] = expand_env(ft_substr(str, *start, gamb->i - *start));
	}
}

char	**get_argv(char *str)
{
	char	**arr;
	int		start;
	t_gamb	gamb;

	arr = malloc(200 * sizeof(char *));
	gamb.x = 0;
	gamb.i = 0;
	while (str[gamb.i])
	{
		while (str[gamb.i] == ' ' && str[gamb.i] != '\0')
			(gamb.i)++;
		get_argv_cont(str, arr, &gamb, &start);
	}
	arr[gamb.x] = 0;
	return (arr);
}
