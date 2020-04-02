# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chlee <chlee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/02 17:34:10 by chlee             #+#    #+#              #
#    Updated: 2020/04/02 23:47:04 by chlee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= factorization

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= factorization.c
OBJS		= factorization.o
BIN_PATH	= /usr/local/bin

.PHONY: all clean flcean re

${NAME} : ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}
	@sudo cp $(NAME) $(BIN_PATH)

all : ${NAME}

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f ${NAME}
	@sudo rm -f $(BIN_PATH)/$(NAME)


re : fclean all
