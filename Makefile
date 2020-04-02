# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chlee <chlee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/02 17:34:10 by chlee             #+#    #+#              #
#    Updated: 2020/04/02 22:51:44 by chlee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= factorization

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= factorization.c
OBJS		= factorization.o

.PHONY: all clean flcean re

${NAME} : ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all : ${NAME}

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f ${NAME}

re : fclean all
