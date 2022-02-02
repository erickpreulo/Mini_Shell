# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomes <egomes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/10 23:55:33 by acanterg          #+#    #+#              #
#    Updated: 2022/02/01 19:45:37 by egomes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isspace.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_strdup.c \

SRCS_2	=	ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c 

SRCS_B	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c 

OBJS	= ${SRCS:.c=.o}
OBJS_2	= ${SRCS_2:.c=.o}
OBJS_B	= ${SRCS_B:.c=.o}
GCC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libft.a

.c.o:
			@${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

all : 		${NAME}

$(NAME) :	${OBJS} ${OBJS_2}
			@ar rc ${NAME} ${OBJS} ${OBJS_2}
			@ranlib ${NAME}

bonus :		${NAME} ${OBJS_B}
			ar rc ${NAME} ${OBJS_B}
			ranlib ${NAME}

clean :
			@rm -f ${OBJS} ${OBJS_2} ${OBJS_B}

teste:		
			${GCC} ${CFLAGS} -fsanitize=address -g ft_split.c ft_substr.c ft_strlcpy.c ft_strlen.c && ./a.out

fclean :	clean
			@rm -f ${NAME}

re :		fclean all

.PHONY: 	all clean fclean re test