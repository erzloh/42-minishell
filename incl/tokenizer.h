/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:55:13 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/29 10:17:08 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../libft/libft.h"

#ifndef TOKENIZER_H
# define TOKENIZER_H

typedef enum
{
	ECHO,				// echo
	CD,					// cd
	PWD,				// pwd
	EXPORT,				// export
	UNSET,				// unset
	ENV,				// env
	EXIT,				// exit
	PIPE,				// |
	INPUT_REDIRECT,		// <
	OUTPUT_REDIRECT,	// >
	HEREDOC_REDIRECT,	// <<
	APPEND_REDIRECT,	// >>
	PATH,
	INVALID,
}	cmd_type;

typedef struct s_token
{
	cmd_type cmd;
	char *arg;
	struct s_token *next;
}	t_token;

void	ft_free_token(t_token *token);
void	ft_display_token(t_token *token);

#endif