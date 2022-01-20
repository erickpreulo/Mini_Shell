/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_clean_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:18:57 by acanterg          #+#    #+#             */
/*   Updated: 2022/01/19 13:32:59 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char *get_clean_str(char *str)
{
	int len;

	
	while (*str == '|' || *str == '>' || *str == '<' || *str == ' ')
		str++;
	len = ft_strlen(str) - 1;
	while (str[len] == ' ')
	{
		str[len] = '\0';
		len--;
	}
	return (str);
}