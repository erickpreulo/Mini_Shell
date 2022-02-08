/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:55:09 by acanterg          #+#    #+#             */
/*   Updated: 2022/02/08 00:46:13 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	**get_argv(char *str)
{
	char	**arr;
	int		i;
	int		start;
	int		x;

	arr = malloc(200 * sizeof(char *));
	x = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' && str[i] != '\0')
			i++;
		if (str[i] == '\"' || str[i] == '\'')
		{
			i++;
			start = i;
			while (str[i] != '\"' && str[i] != '\'')
				i++;
			if (str[i] == '\"')
				arr[x++] = expand_env(ft_substr(str, start, i - start));
			else
				arr[x++] = ft_substr(str, start, i - start);
			i++;
		}
		else
		{
			start = i;
			while (str[i] != ' ' && str[i] != '\"'
				&& str[i] != '\'' && str[i] != '\0')
				i++;
			arr[x++] = expand_env(ft_substr(str, start, i - start));
		}
	}
	arr[x] = 0;
	return (arr);
}
