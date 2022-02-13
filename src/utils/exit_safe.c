/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_safe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 03:32:37 by acanterg          #+#    #+#             */
/*   Updated: 2022/02/13 17:23:42 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	exit_safe(void)
{
	t_mini_shell	*ms;

	ms = get_ms();
	free_lst_env();
	clean_up();
	exit(ms->exit_num);
}
