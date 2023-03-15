# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 14:21:14 by eholzer           #+#    #+#              #
#    Updated: 2023/03/15 15:15:55 by alesspal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

SRCS_DIR	=	sources/
OBJS_DIR	=	objects/

SRCS_LIST	=	main.c \
				signal.c

#SRCS		=	${addprefix ${SRCS_DIR}, ${SRCS_LIST}}

OBJS_LIST	=	${SRCS_LIST:.c=.o}

OBJS		=	${addprefix ${OBJS_DIR}, ${OBJS_LIST}}

all:			${NAME}

${OBJS_DIR}:
				mkdir ${OBJS_DIR}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
				${CC} ${CFLAGS} -c $^ -o $@

${NAME}:		${OBJS_DIR} ${OBJS}
				${CC} ${CFLAGS} ${OBJS} -lreadline -o ${NAME}

clean:
				rm -rf ${OBJS_DIR}

fclean:			clean
				rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re