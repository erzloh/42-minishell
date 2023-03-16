/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:28:45 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/16 17:15:01 by alesspal         ###   ########.fr       */
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
t_token	laxing_cmd(char *input);

// expender
t_token	expend_cmd(t_token token);

// executor
void	execute_cmd(char *input);

// cmd
// ...
// ...

// signal managemenent
void	sigINGORE_handler(int sig);
void	sigINT_handler(int signum);
int		init_signal(int signum, void(*handler)(int));
