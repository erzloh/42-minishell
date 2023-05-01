/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:28:45 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/01 15:03:10 by eholzer          ###   ########.fr       */
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
int		process_input(char *input, t_data *data);

// Path
int		set_cmd_path(t_token *token, char **env_arr);
int		search_cmd_in_path(char **path_arr, t_token *token);

// Utils
int		print_error(char *err_msg, int ret_val);
void	fatal_error(char *err_msg);
char	*ft_getenv(char *name);
int		is_builtin(t_token *token);

// Executor
int		executor(t_token *token, t_data *data);

// Children
void	create_children(t_token *token, t_data *data);
int		exec_single_cmd(t_token *token, t_data *data);
void	exec_builtin(t_token *token, t_data *data);
void	wait_children(t_token *token);

// Built-ins
int		echo(t_token *token);

#endif
