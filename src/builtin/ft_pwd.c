/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:29:33 by egomes            #+#    #+#             */
/*   Updated: 2022/02/11 04:36:30 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_pwd(void)
{
	char	*dir;

	dir = get_current_dir();
	ft_putendl_fd(dir, get_ms()->fd_exit);
	free(dir);
	return (0);
}
