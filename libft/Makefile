# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 19:07:10 by apalumbi          #+#    #+#              #
#    Updated: 2023/05/10 17:38:35 by alesspal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra

STD_DIR			=	std
GNL_DIR			=	gnl
FT_PRINTF_DIR	=	ft_printf
SRCS_DIR		=	srcs
SRCS_STD_DIR	=	$(STD_DIR)/$(SRCS_DIR)
SRCS_GNL_DIR	=	$(GNL_DIR)/$(SRCS_DIR)
SRCS_FT_PRINTF_DIR	=	$(FT_PRINTF_DIR)/$(SRCS_DIR)
INCL_DIR		=	incl
OBJS_DIR		=	objs

SRCS_STD		=	ft_memset.c \
					ft_bzero.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_strlen.c \
					ft_strlcpy.c \
					ft_strlcat.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strnstr.c \
					ft_strncmp.c \
					ft_atoi.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_is_white_space.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_calloc.c \
					ft_strdup.c \
					ft_strndup.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_strjoin3.c \
					ft_strtrim.c \
					ft_split.c \
					ft_itoa.c \
					ft_strmapi.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_striteri.c \
					ft_lstnew_bonus.c \
					ft_lstadd_front_bonus.c \
					ft_lstsize_bonus.c \
					ft_lstlast_bonus.c \
					ft_lstadd_back_bonus.c \
					ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c \
					ft_lstiter_bonus.c \
					ft_lstmap_bonus.c \
					ft_str_arr_len.c \
					ft_malloc_2d_int.c \
					ft_free_2d_int.c \
					ft_display_2d_int.c \
					ft_free_2d_char.c \
					ft_str_arrdup.c \
					ft_str_arr_alpsort.c \
					ft_str_arr_cat.c \
					ft_add_element_to_stack.c \
					ft_malloc_stack.c \
					ft_free_stack.c \
					ft_fatal_error.c \

SRCS_GNL		=	get_next_line.c \
					get_next_line_utils.c \
					get_next_line_bonus.c \
					get_next_line_utils_bonus.c \
					ft_read_file.c

SRCS_FT_PRINTF	=	format.c \
					ft_itoh.c \
					ft_lltoh.c \
					ft_printf.c \
					ft_uitoa.c \
					update_aff.c \
					utils.c

OBJS_LIST		=	$(SRCS_STD:.c=.o) $(SRCS_GNL:.c=.o) $(SRCS_FT_PRINTF:.c=.o)
OBJS			=	$(addprefix $(OBJS_DIR)/,$(OBJS_LIST))

INCL_DIRS		= -I $(STD_DIR)/$(INCL_DIR) -I $(GNL_DIR)/$(INCL_DIR) -I $(FT_PRINTF_DIR)/$(INCL_DIR) -I .
VPATH			= $(SRCS_STD_DIR):$(SRCS_GNL_DIR):$(SRCS_FT_PRINTF_DIR)

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCL_DIRS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
