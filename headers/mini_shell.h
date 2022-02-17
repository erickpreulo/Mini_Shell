/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:20:19 by egomes            #+#    #+#             */
/*   Updated: 2022/02/17 15:32:55 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdbool.h>
# include <dirent.h>
# include <termios.h>
# include "../libft/libft.h"

// **       DEFINE      **

# define C_PIPE "|"
# define C_FILE_IN "<"
# define C_FILE_OUT ">"
# define C_FILE_APPEND ">>"
# define C_FILE_DELIMITER "<<"

# define PIPE_READ 0
# define PIPE_WRITE 1

# define MAX_BLOCKS 256

// ***      STRUCT      ***

typedef enum s_type_sep
{
	T_FIRST,
	T_PIPE,
	T_FILE_IN,
	T_FILE_OUT,
	T_FILE_APPEND,
	T_FILE_DELIMITER
}	t_type_sep;

typedef struct s_env
{
	char	*key;
	char	*str;
}			t_env;

typedef struct s_block
{
	char		*path_cmd;
	char		*cmd;
	char		**argv;
	t_type_sep	type;
	char		*str;
	int			fd;
	int			group;
	bool		last_of_group;
	int			pipe[2];
}				t_block;

typedef struct s_mini_shell
{
	t_block	blocks[MAX_BLOCKS];
	int		group_size;
	int		size;
	int		fd_in[MAX_BLOCKS];
	int		fd_out[MAX_BLOCKS];
	char	**env;
	t_list	**lst_env;
	int		fd_exit;
	int		fd_enter;
	int		final_status;
	int		sig_exit;
	int		exit_num;
	bool	has_interrogation_key;
	bool	searching_new_group;
	pid_t	last_pid;
}			t_mini_shell;

typedef struct s_gamb
{
	int	i;
	int	x;
	int	start;
}				t_gamb;

// ******   SRC   ****** 

// ****    main_functions   ****

int				ft_echo(int i);
int				ft_env(void);
int				ft_export(int i);
int				ft_pwd(void);
int				ft_unset(int i);
int				ft_exit(int i);
int				ft_cd(int i);

// ****    other_functions   ****

int				find_outfile(char **argv);
int				ft_execve(int i);
t_mini_shell	*get_ms(void);
void			parse(char *line);
void			create_block(char *str);
char			**get_argv(char *str);
char			*get_clean_str(char *str);
int				open_file_output(char *file_name, int group);
int				open_file_append(char *file_name, int group);
int				open_file_input(char *file_name, int group);
int				open_file_delimiter(char *file_name,
					char *delimiter, int group);
char			*get_path_cmd(char *cmd);
t_type_sep		get_type(char *str);
bool			is_file(t_type_sep type);
int				ft_exec_pipe(int i);
int				ft_executor(void);
void			print_blocks(void);
int				ft_exec_pipe(int i);
void			ft_pipe(int i);
void			ft_redirect(int i);
void			redirect_input(int i);
void			redirect_output(int i);
int				select_cmd(int i);
char			*get_current_dir(void);
void			free_stuff(void);
int				get_next_line(char **line);
void			ft_pipe_old(int i);
void			ft_redirect_old(int i);
void			reset_struct(void);
void			get_env_list(char **env);
t_env			*create_t_env(char *line);
t_env			*get_env(char *key);
int				update_or_create_env(char *str);
char			*get_env_value(char *key);
char			*expand_env(char *str);
char			**get_env_temp(void);
void			free_lst_env(void);
int				get_next_line(char **line);
void			clean_up(void);
void			start_signal(void);
void			exit_safe(void);
bool			check_valid_file(char *line);
bool			is_separator(char c);
void			del_env_content(void *env_temp);
void			show_pwd(void);
char			*get_line(void);
void			check_old_fd(int fd_old);

#endif
