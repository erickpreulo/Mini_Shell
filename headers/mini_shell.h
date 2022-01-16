/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:20:19 by egomes            #+#    #+#             */
/*   Updated: 2022/01/14 11:28:13 by egomes           ###   ########.fr       */
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

# include "../libft/libft.h"

// **       DEFINE      **

#define C_PIPE "|"
#define C_FILE_IN "<"
#define C_FILE_OUT ">"
#define C_FILE_APPEND ">>"


// ***      STRUCT      ***

typedef enum
{
    T_CMD,
    T_PIPE,
    T_FILE_IN,
    T_FILE_OUT,
    T_FILE_APPEND
} type_sep;

typedef struct s_block
{
    char *path_cmd; // /bin/cat
    char *cmd;      // /cat
    char **argv;     // ['cat', 'file1.txt']
    type_sep type;
    char *str; // "cat file1.txt"
    int fd;          // 0
    int is_first;
    int is_last;
}               t_block;

typedef struct s_mini_shell
{
    char separation[20][3];
    char str[20][2000];
    char **contact;
    int s_count;
    int c_count;


    t_block blocks[50];
    int size;
    int fd_in;
    int fd_out;
    int last_cmd;
    int fd_pipes[50][2];
    int current_pipe;

}               t_mini_shell;


// ******   SRC   ****** 

// ****    main_functions   ****

int	ft_echo(char **command);
int	ft_env(char **command);
int	ft_export(char **command);
int	ft_pwd(char **command);
int	ft_unset(char **command);
void	ft_access(char **command);

// ****    other_functions   ****


int	find_outfile(char **argv);
int	ft_execve(int i);
t_mini_shell *get_ms();
void parse(char *line);
int	take_block(char *str, int i);

char **get_argv(char *str);
char *get_clean_str(char *str);
int open_file_output(char *file_name);
int open_file_append(char *file_name);
int open_file_input(char *file_name);
char *get_path_cmd (char *cmd);
type_sep get_type(char *str);

int	ft_exec_pipe(int i);
int		ft_executor();

#endif