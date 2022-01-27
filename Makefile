# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomes <egomes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 11:37:32 by egomes            #+#    #+#              #
#    Updated: 2022/01/27 14:58:20 by egomes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 		mini_shell.c src/*/*.c
NAME = 		mini_shell
INCLUD = 	-I headers
CC = 		gcc
CFLAGS = 	-Wall -Wextra -Werror
AR = 		ar rcs
LIBFT = 	libft
LIBS	=	-L./$(LIBFT) -g -lft -lreadline -I .brew/opt/readline/include

del:		re
			./mini_shell

all:		$(NAME)

$(NAME):	lib
			@echo "mini_shell..."
			@$(CC) $(CFLAGS) $(INCLUD) $(SRC) $(LIBS) -o $(NAME)
			@rm -rf *.dSYM
			@echo ">>> mini_shell done!"


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

