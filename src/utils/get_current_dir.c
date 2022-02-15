/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:12:40 by egomes            #+#    #+#             */
/*   Updated: 2022/02/15 16:12:54 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*get_current_dir(void)
{
	char	*directory;

	directory = malloc(sizeof(char) * 256);
	getcwd(directory, 256);
	return (directory);
}
