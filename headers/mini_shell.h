/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:20:19 by egomes            #+#    #+#             */
/*   Updated: 2022/01/20 16:07:22 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINI_SHELL_H
# define MINI_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <stdbool.h>



# include "../libft/libft.h"

// **       DEFINE      **

#define C_PIPE "|"
#define C_FILE_IN "<"
#define C_FILE_OUT ">"
#define C_FILE_APPEND ">>"


// ***      STRUCT      ***

typedef enum
{
    T_FIRST,
    T_PIPE,
    T_FILE_IN,
    T_FILE_OUT,
    T_FILE_APPEND
} type_sep;

typedef struct s_block
{
    char *path_cmd;
    char *cmd;
    char **argv;
    type_sep type;
    char *str;
    int fd;
    int group;
    bool first_of_group;
    bool last_of_group;
}               t_block;

typedef struct s_mini_shell
{
    char separation[20][3];
    char str[20][2000];
    char **contact;
   
    t_block blocks[50];
    int group_size;
    int size;
    int fd_in[50];
    int fd_out[50];
    int is_pipe;
    int fd[50][2];
    int pid[50];
    int current_pipe;
    int i;
    char** env;

}               t_mini_shell;


// ******   SRC   ****** 

// ****    main_functions   ****

int	ft_echo(char **command);
int	ft_env(char **command);
int	ft_export(char **command);
int	ft_pwd(char **command);
int	ft_unset(char **command);

// ****    other_functions   ****

int	find_outfile(char **argv);
int	ft_execve(int i);
t_mini_shell *get_ms();
void parse(char *line);
void	create_block(char *str);

char **get_argv(char *str);
char *get_clean_str(char *str);
int open_file_output(char *file_name);
int open_file_append(char *file_name);
int open_file_input(char *file_name);
char *get_path_cmd (char *cmd);
type_sep get_type(char *str);
bool is_file(type_sep type);

int	ft_exec_pipe(int i);
int		ft_executor();
void	print_blocks();
int	ft_exec_pipe(int i);
void	ft_pipe(int i);
int open_file_output(char *file_name);
int open_file_append(char *file_name);
int open_file_input(char *file_name);
void	ft_redirect(int i);

#endif