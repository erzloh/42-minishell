# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 14:21:14 by eholzer           #+#    #+#              #
#    Updated: 2023/05/15 17:05:45 by alesspal         ###   ########.fr        #
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
				path.c \
				utils1.c \
				executor.c \
				children.c \
				children2.c \
				echo.c \
				pipes.c \
				redirections.c \
				redirections2.c \
				exec.c \
				exit.c \
				pwd.c \
				cd.c \
				env_utils.c \
				env_builtin.c \
				env.c \
				export.c \
				unset.c \
				token_manager.c \
				check_input_syntax.c \
				check_input_syntax_utils.c \
				quote_manager.c \
				lexer.c \
				lexer_utils.c \
				expander.c

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