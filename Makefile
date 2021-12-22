# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomes <egomes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 11:37:32 by egomes            #+#    #+#              #
#    Updated: 2021/12/20 20:24:51 by egomes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = mini_shell.c src/*/*

NAME = mini_shell

INCLUD = -I headers

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

.c.o:
			@$(CC)  $(CFLAGS) $(INCLUD) -c $< -o $(<:.c=.o)

OBJ = $(SRC:.c=.o)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(INCLUD) $(OBJ) -o $(NAME)
			
all:		$(NAME)

clean:
		${shell find . -type f -name "*.o" -delete}

fclean: clean
	@rm -f $(NAME)

re: fclean all
