/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:28:45 by alesspal          #+#    #+#             */
/*   Updated: 2023/04/27 10:26:20 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <unistd.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "tokenizer.h"

// Macros
# define MALLOC_ERR -42
// # define MILD_ERR -43 
// # define CMD_NOT_FOUND -44 

// Structures
typedef struct s_data
{
    t_token *token; // pointer to the first token
    char    **env_arr; // a COPY of envp
    char    *line; // (maybe we don't need that here)
    char    **line_elem; // Result of the expander (maybe we don't need that here)
}	t_data;

// Function prototypes
void	process_input(char *input);

#endif
