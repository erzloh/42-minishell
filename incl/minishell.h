/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:28:45 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/03 13:17:47 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include "../libft/libft.h"
#include "tokenizer.h"
#include "env.h"

typedef struct s_data
{
	int		tokens_nb;
    struct s_token *token; // pointer to the first token
    char    **env_arr; // a COPY of envp
    char    *line; // (maybe we don't need that here)
	int		**pipe_fd;
}	t_data;

bool	check_unmatched_quotes(char *str);

#endif