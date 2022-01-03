/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:20:19 by egomes            #+#    #+#             */
/*   Updated: 2022/01/03 12:30:16 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINI_SHELL_H
# define MINI_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>

# include <readline/readline.h>
# include <readline/history.h>

# include <signal.h>

int	get_next_line(char **line);
int	bin(char **argv, int i);
int	pwd(char **argv);
int	null_buffer(char *buffer);
int	ft_strcmp(char *s1, char *s2);
char		**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int	usr_bin(char **argv);
int	touch(char *str);
int	find_arrow(char **argv);
int	ft_execve(char **argv, int i, char *str);

#endif