/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:20:19 by egomes            #+#    #+#             */
/*   Updated: 2022/01/06 15:18:54 by egomes           ###   ########.fr       */
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
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

// **       DEFINE      **

#define OUT_FILE ">"
#define APEND_FILE ">>"

#define CMD 0
#define FILE_IN 1
#define FILE_OUT 2
#define FILE_APPEND 3
#define PIPE 4

// ***      STRUCT      ***

typedef struct s_block
{
    char *cmd;
    char *path_cmd;
}               t_block;

typedef struct s_mini_shell
{
    int is_out_file;
    t_block blocks[20];
}               t_mini_shell;


// ******   SRC   ****** 

// ****    main_functions   ****

int	ft_echo(char **command, int i);
int	ft_env(char **command, int i);
int	ft_export(char **command, int i);
int	ft_pwd(char **command, int i);
int	ft_unset(char **command, int i);
void	ft_access(char **command, int i);

// ****    other_functions   ****

int	get_next_line(char **line);
int	ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int	find_arrow(char **argv);
int	ft_execve(char **argv, int i, char *str);
t_mini_shell *get_ms();


/*t_struct Block {
    cmd: String // ls ,echo, ... null
    str_cmd: // /usr/ls  usr/bin/echo usr/python/py  ... null
    type: // cmd, cd, in_file, out_file, append_file, pipe         > < >>,
    argv: 
    file: f


}*/

#endif