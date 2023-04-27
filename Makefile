# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 14:21:14 by eholzer           #+#    #+#              #
#    Updated: 2023/04/27 10:32:12 by eholzer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g

LIBFT		=	libft.a

SRCS_DIR	=	srcs/
OBJS_DIR	=	objs/

SRCS_LIST	=	main.c \
				process_input.c \
				# cd.c \
				# path.c \
				# _executor.c \
				# children.c \
				# cmds_arr.c \
				# command.c \
				# pipes.c \
				# utils_1.c \
				# free_memory.c \
				# check_errors.c \
				# executor.c \
				# env.c \
				# env_utils.c \
				# token_utils.c \
				# laxer.c \
				# laxer_utils.c \
				# expender.c \
				# execution_main.c \

OBJS_LIST	=	${SRCS_LIST:.c=.o}

OBJS		=	${addprefix ${OBJS_DIR}, ${OBJS_LIST}}

all:			${LIBFT} ${NAME}

${OBJS_DIR}:
				mkdir ${OBJS_DIR}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
				${CC} ${CFLAGS} -Iincl/ -c $^ -o $@

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