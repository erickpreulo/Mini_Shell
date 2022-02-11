/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 01:27:57 by egomes            #+#    #+#             */
/*   Updated: 2022/02/11 01:32:33 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void    clean_up(void)
{
    t_mini_shell *ms;
    int i;

    ms = get_ms();
    i = 0;
    while (i < ms->group_size)
    {
        if (ms->fd_in[i] > 0)
            close(ms->fd_in[i]);
        if (ms->fd_out[i] > 0)
            close(ms->fd_out[i]);
        i++;
    }
    unlink(".temp");
}