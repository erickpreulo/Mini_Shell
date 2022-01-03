# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomes <egomes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 11:37:32 by egomes            #+#    #+#              #
#    Updated: 2021/12/23 14:07:44 by egomes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = mini_shell.c src/*/*.c

NAME = mini_shell

INCLUD = -I headers

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

.c.o:
			@$(CC)  $(CFLAGS)  $(INCLUD) -c $< -o $(<:.c=.o)

OBJ = $(SRC:.c=.o)

$(NAME):	
			@$(CC) $(CFLAGS)  $(INCLUD) $(SRC) -lreadline -I .brew/opt/readline/include -o $(NAME)
			
all:		$(NAME)

clean:
		${shell find . -type f -name "*.o" -delete}

fclean: clean
	@rm -f $(NAME)

re: fclean all
