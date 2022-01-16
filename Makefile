# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomes <egomes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 11:37:32 by egomes            #+#    #+#              #
#    Updated: 2022/01/13 18:10:19 by egomes           ###   ########.fr        #
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

$(NAME):	
			@$(CC) $(CFLAGS) $(INCLUD) $(SRC) $(LIBS) -o $(NAME)

all:		$(NAME)

clean:
		${shell find . -type f -name "*.o" -delete}

fclean: clean
	@rm -f $(NAME)

re: fclean all
