/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:00:33 by egomes            #+#    #+#             */
/*   Updated: 2022/02/10 19:17:15 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void    exit_error(int i, char *cmd)
{
    printf("\033[0;32mCyber38@TM \033[0;31m%%> \033[0m: %s: %s\n", cmd, strerror(i));
}
