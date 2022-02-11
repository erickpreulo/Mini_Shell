# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomes <egomes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 11:37:32 by egomes            #+#    #+#              #
#    Updated: 2022/02/10 21:58:37 by egomes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 		minishell.c src/*/*.c
NAME = 		minishell
INCLUD = 	-I headers
CC = 		gcc
CFLAGS = 	-Wall -Wextra -Werror
AR = 		ar rcs
LIBFT = 	libft
LIBS	=	-L./$(LIBFT) -g -lft
RL     =    -I ~/.brew/opt/readline/include -L ~/.brew/opt/readline/lib -lreadline

del:		re
			./minishell

all:		$(NAME)

$(NAME):	lib
			@echo "minishell..."
			@$(CC) $(CFLAGS) $(INCLUD) $(SRC) $(LIBS) $(RL) -o $(NAME)
			@rm -rf *.dSYM
			@echo ">>> minishell done!"


lib:	
		@echo "libft..."
		@make re -C $(LIBFT)
		@make clean -C $(LIBFT)
		@echo ">>> libft done!"

clean:
		${shell find . -type f -name "*.o" -delete}

fclean: clean
		@make fclean -C $(LIBFT)
		@rm -f $(NAME)

re: 	fclean all

