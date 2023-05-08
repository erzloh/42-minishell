/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:28:45 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/08 15:01:55 by eric             ###   ########.fr       */
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
# include <fcntl.h>
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
	int		**pipe_fd;
	int		tokens_nb;
}	t_data;

// Function prototypes
int		process_input(char *input, t_data *data);

// Path
int		set_cmd_path(t_token *token, char **env_arr);
int		search_cmd_in_path(char **path_arr, t_token *token);
void	set_cmd_path_in_all_token(t_token *token, char **env_arr);

// Utils
int		print_error(char *err_msg, int ret_val);
void	fatal_error(char *err_msg);
char	*ft_getenv(char *name);
int		is_builtin(t_token *token);
int 	is_str_digit(char *str);

// Executor
int		executor(t_token *token, t_data *data);

// Children
void	create_children(t_token *token, t_data *data);
void	check_infile(t_token *token, t_data *data);
void	set_dups(t_token *token);
void	clean_up(t_token *token, t_data *data);
void	wait_children(t_token *token);
int 	is_cmd_childable(t_token *token);

// Exec
int		exec_external(t_token *token, t_data *data);
void	exec_builtin(t_token *token, t_data *data);

// Built-ins
int		echo(t_token *token);
void	exit_builtin(t_token *token);
void	pwd(void);

// Pipes
void	create_pipes(t_data *data);
void	close_pipes(t_token *token, t_data *data);
void	set_pipe_fd_in_token(t_token *token, t_data *data);
void	free_pipe_fd(t_token *token, t_data *data);

// Redirections
void	set_redirect_fd_in_token(t_token *token);
void	set_input_redirect(t_token *token);
void	set_heredoc_redirect(t_token *token);
void	set_output_redirect(t_token *token);
void	set_append_redirect(t_token *token);
void	close_redirect_files(t_token *token);

// Tokens
void	init_token(t_token *token);

#endif
