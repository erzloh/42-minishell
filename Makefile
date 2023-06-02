# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 14:21:14 by eholzer           #+#    #+#              #
#    Updated: 2023/06/02 10:36:47 by eholzer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g -I$(HOME)/.brew/opt/readline/include

INCL_PATH	=	-Iincl/ \
				-I$(HOME)/.brew/opt/readline/include
				# -I/usr/local/opt/readline/include
				# -I//opt/homebrew/Cellar/readline/8.2.1/include

LIBS		=	-Llibft -lft -lreadline \
				-L$(HOME)/.brew/opt/readline/lib
				# -L/usr/local/opt/readline/lib
				# -L/opt/homebrew/Cellar/readline/8.2.1/lib

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
				expander.c \
				signals.c \
				termios.c \
				free_data.c \

OBJS_LIST	=	${SRCS_LIST:.c=.o}

OBJS		=	${addprefix ${OBJS_DIR}, ${OBJS_LIST}}

READLINE	=	-lreadline -L$(HOME)/.brew/opt/readline/lib

all:			${LIBFT} ${NAME}

${OBJS_DIR}:
				mkdir ${OBJS_DIR}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
				${CC} ${CFLAGS} ${INCL_PATH} -c $^ -o $@

${NAME}:		${OBJS_DIR} ${OBJS}
				${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

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