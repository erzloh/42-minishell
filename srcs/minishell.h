/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:28:45 by alesspal          #+#    #+#             */
/*   Updated: 2023/04/06 20:17:33 by eric             ###   ########.fr       */
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
#include <sys/wait.h>
#include "../libft/libft.h"

// tokenizer.h

// typedef enum
// {
// 	ECHO,				// echo
// 	CD,					// cd
// 	PWD,				// pwd
// 	EXPORT,				// export
// 	UNSET,				// unset
// 	ENV,				// env
// 	EXIT,				// exit
// 	PIPE,				// |
// 	INPUT_REDIRECT,		// <
// 	OUTPUT_REDIRECT,	// >
// 	HEREDOC_REDIRECT,	// <<
// 	APPEND_REDIRECT,	// >>
// 	PATH,
// 	INVALID,
// }	cmd_type;

typedef struct s_token
{
	char	*cmd;
	char	*arg;
	struct 	s_token *next;
}	t_token;