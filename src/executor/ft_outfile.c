/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:31:30 by egomes            #+#    #+#             */
/*   Updated: 2022/01/13 17:25:33 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

// int	find_outfile(char **argv)
// {
// 	int i;
// 	int fd;

// 	i = 0;
// 	while (argv[i])
// 	{
// 		if (ft_strcmp(argv[i], C_FILE_OUT) == 0
// 			|| ft_strcmp(argv[i], C_FILE_APPEND) == 0)
// 		{
// 			if (ft_strcmp(argv[i], C_FILE_OUT) == 0)
// 				fd = open(argv[i + 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
// 			else
// 				fd = open(argv[i + 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
// 			dup2(fd, 1);
// 			argv[i] = NULL;
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }
