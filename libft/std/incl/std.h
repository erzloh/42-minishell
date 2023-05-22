/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:09:25 by marvin            #+#    #+#             */
/*   Updated: 2023/05/22 17:23:10 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STD_H
# define STD_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/// @brief check if is an alphabetic character
/// @param c ascii character value
/// @return 1 : if it's an alphabetic character, 0 : if it's not
int					ft_isalpha(int c);

/// @brief check if is a digit character
/// @param c ascii character value
/// @return 1 : if it's a digit character, 0 : if it's not
int					ft_isdigit(int c);

/// @brief check if is an alphanumeric character
/// @param c ascii character value
/// @return 1 : if it's an alphanumeric character, 0 : if it's not
int					ft_isalnum(int c);

/// @brief check if is an ascii character
/// @param c ascii character value
/// @return 1 : if it's an ascii character, 0 : if it's not
int					ft_isascii(int c);

/// @brief check if is a printable character
/// @param c ascii character value
/// @return 1 : if it's a printable character, 0 : if it's not
int					ft_isprint(int c);

/// @brief check if is a whitespace (if it is ASCII 32/9/10/11/12/13)
/// @param c ascii character value
/// @return 1 : if it's a whitespace character, 0 : if it's not
int					ft_is_white_space(int c);

/// @brief calculates the size of string
/// @param str string to calculate
/// @return the size of string
size_t				ft_strlen(const char *str);

size_t				ft_strlcpy(char *dest, const char *src, size_t size);

/// @brief calculates the size of concatenated strings and add src in dest
/// @param dest final word string
/// @param src string to add in dest
/// @param size final dest size
/// @return size of (dest + src)
size_t				ft_strlcat(char *dest, const char *src, size_t size);

char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strnstr(const char *str, const char *to_find, \
					size_t len);

/// @brief concatenates two strings together
/// @param s1 string one
/// @param s2 string two
/// @return the concatenated string
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strjoin3(const char *s1, const char *s2,
						const char *s3);
char				*ft_strtrim(char *s1, char const *set);

/// @brief split a string into multiple strings with a separator
/// @param s string to split
/// @param c separator
/// @return an array of strings
char				**ft_split(char const *s, char c);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_substr(char const *s, unsigned int start, size_t len);

/// @brief converted a number in string
/// @param n number to convert
/// @return a string of number
char				*ft_itoa(int n);

/// @brief converted a string in number
/// @param str string to convert
/// @return 0 : if it's not a convertible number, or the number in integer
int					ft_atoi(const char *str);

/// @brief compares two strings
/// @param s1 string one
/// @param s2 string two
/// @param n size of number of characters we want to compare
/// @return 0 : if they are identical, positif number : if s1 is bigger,
/// negatif number : if s2 is bigger
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/// @brief converted a lowercase letter in uppercase lettre
/// @param c lettre to convert
/// @return uppercase lettre
int					ft_toupper(int c);

/// @brief converted a uppercase letter in lowercase lettre
/// @param c lettre to convert
/// @return lowercase lettre
int					ft_tolower(int c);

void				*ft_memset(void *str, int c, size_t n);
void				ft_bzero(void *str, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);

/// @brief copy a string to another string by allocating a memory to it
/// @param str string to copy
/// @return str copied with allocated memory
char				*ft_strdup(const char *str);
char				*ft_strndup(const char *src, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
					void (*del)(void *));
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
int					ft_lstsize(t_list *lst);

int					**ft_malloc_2d_int(int row, int col);
void				ft_free_2d_int(int **tab, int row);
void				display_2d_int(int **tab, int row, int col);
void				ft_free_2d_char(char **c);
char				**ft_str_arrdup(char **str_arr);
void				ft_str_arr_alpsort(char ***str_arr);
int					ft_str_arr_len(char **str_arr);
char				**ft_str_arr_cat(char **str_arr, const char *new_str);

typedef struct s_stack{
	int	*tab;
	int	size;
	int	lenght_allocated;
}	t_stack;

t_stack				*ft_malloc_stack(int len);
t_stack				*ft_malloc_and_cpy_stack(t_stack *stack);
void				free_stack(t_stack *to_freed);
t_stack				*ft_add_t_stack_element(t_stack *stack, int element);

typedef enum e_error
{
	E_ERROR_ARG = 1,
	E_ERROR_MALLOC = 2,
}	t_error;

void				ft_fatal_error(char *err_msg, int ret_err);

#endif
