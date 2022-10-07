# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afonso <afonso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 17:21:03 by atereso-          #+#    #+#              #
#    Updated: 2022/10/06 11:37:47 by afonso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minitalk
HEADER := -I./
OBJS_S := ./server_assets/server.o
OBJS_C := ./client_assets/client.o
CC := gcc
CFLAGS := -Wall -Wextra -Werror
LIBPATHS := -L./ -lftprintf
RM := rm -f

all:linux

$(NAME): ${OBJS}
	$(CC) $(OBJS) -o $(NAME)

linux: $(OBJS) server client

test:${OBJS} ${OBJS_T}
	${CC} ${CFLAGS} so_long_tester.c ${OBJS} -o tester

server:${OBJS_S}
	$(CC) $(HEADER) $(OBJS_S) ${LIBPATHS} -o server

client:${OBJS_C}
	$(CC) $(HEADER) $(OBJS_C) ${LIBPATHS} -o client

libftprintf.a:
	${MAKE} -C ../printf42
	mv ../printf42/libftprintf.a /home/afonso/Documents/GitHub/so_long_home
	${MAKE} -C ../printf42 clean
	${MAKE} -C ../printf42/libft clean

clean:
	${RM} ${OBJS_S} ${OBJS_C} 

fclean: clean
	${RM} ${NAME}
	${RM} linux
	${RM} server
	${RM} client
	${RM} tester

re: fclean all

.PHONY: all re clean fclean bonus fetch fetchl
