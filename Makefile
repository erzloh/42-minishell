# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 14:21:14 by eholzer           #+#    #+#              #
#    Updated: 2023/03/17 10:16:50 by alesspal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

LIBFT		=	libft.a

SRCS_DIR	=	srcs/
OBJS_DIR	=	objs/

SRCS_LIST	=	main.c \
				signal.c \
				executor.c \
				parse.c \
				env.c \

OBJS_LIST	=	${SRCS_LIST:.c=.o}

OBJS		=	${addprefix ${OBJS_DIR}, ${OBJS_LIST}}

all:			${LIBFT} ${NAME}

${OBJS_DIR}:
				mkdir ${OBJS_DIR}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
				${CC} ${CFLAGS} -c $^ -o $@

${NAME}:		${OBJS_DIR} ${OBJS}
				${CC} ${CFLAGS} ${OBJS} -Llibft -lft -lreadline -o ${NAME}

${LIBFT}:
				$(MAKE) -C libft

clean:
				rm -rf ${OBJS_DIR}
				$(MAKE) -C libft clean

fclean:			clean
				rm -f ${NAME}
				$(MAKE) -C libft fclean

re:				fclean all

.PHONY:			all clean fclean re