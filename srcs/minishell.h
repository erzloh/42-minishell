/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:28:45 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/17 17:19:04 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include "../libft/libft.h"

typedef enum
{
	E_ECHO,				// echo
	CD,					// cd
	PWD,				// pwd
	EXPORT,				// export
	UNSET,				// unset
	ENV,				// env
	EXIT,				// exit
	INPUT_REDIRECT,		// <
	OUTPUT_REDIRECT,	// >
	HEREDOC_REDIRECT,	// <<
	APPEND_REDIRECT,	// >>
	NOTHING
} cmd_type;

typedef struct s_token
{
	cmd_type cmd;
	char *arg;
	struct s_token *next;
} t_token;

// laxer
t_token	ft_laxing_cmd(char *input);

// expender
t_token	ft_expend_cmd(t_token token);

// executor
void	ft_execute_cmd(char *input);

// env
int		ft_is_dollar(int c);
int		ft_setenv(const char *name, const char *value);
int		ft_unsetenv( char *name);
char	*ft_getenv(char *name);
void	ft_get_all_env();
char	*ft_findenv(const char *input);
int my_setenv(const char *name, const char *value, int overwrite);
// signal managemenent
void	ft_sigINGORE_handler(int sig);
void	ft_sigINT_handler(int signum);
int		ft_init_signal(int signum, void(*handler)(int));
