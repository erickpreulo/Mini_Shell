/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_separator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 06:02:39 by egomes            #+#    #+#             */
/*   Updated: 2022/01/07 06:17:15 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	block_separator(char **command)
{
	t_mini_shell *ms;
	int i;

	ms = get_ms();
	i = 0;
	while (command[i] != 0)
	{
		ms->blocks[i].cmd = command[i];
	}
}