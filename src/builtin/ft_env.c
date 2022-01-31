/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:25:45 by egomes            #+#    #+#             */
/*   Updated: 2022/01/31 17:01:19 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_env(int i)
{
	t_mini_shell *ms;
	char **env;
	(void) i;
	
	ms = get_ms();
	env = ms->env;

	while(*env)
		ft_putendl_fd(*(env++), ms->fd_exit);
	return (0);
}

