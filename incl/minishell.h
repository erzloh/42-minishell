/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:28:45 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/22 15:10:35 by alesspal         ###   ########.fr       */
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
# include <termios.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <termios.h>
# include "../libft/libft.h"
# include "tokenizer.h"
# include "env.h"
// Macros

# define MALLOC_ERR -42
// # define MILD_ERR -43 
// # define CMD_NOT_FOUND -44 

// Structures
typedef struct s_data
{
	t_token	*token; // pointer to the first token
    char    **envp_cpy; // a COPY of envp
    char    *input;
    char    **formatted_input;
	int		**pipe_fd;
	int		tokens_nb;
}	t_data;

// Function prototypes
int		process_input(t_data *data);

// Data management
void	init_data(t_data *data, char **envp);
void	ft_free_data(t_data *data);

// Path
int		set_cmd_path(t_token *token, char **envp_cpy);
int		search_cmd_in_path(char **path_arr, t_token *token);
void	set_cmd_path_in_all_token(t_token *token, char **envp_cpy);

// Utils
int		print_error(char *err_msg, int ret_val);
void	fatal_error(char *err_msg);
int		is_builtin(t_token *token);
int		is_str_digit(char *str);

// Executor
int		executor(t_token *token, t_data *data);

// Children
void	create_children(t_token *token, t_data *data);
void	check_infile(t_token *token, t_data *data);
void	set_dups(t_token *token);
void	clean_up(t_token *token, t_data *data);
void	wait_children(t_token *token);
int		is_cmd_childable(t_token *token);

// Exec
int		exec_external(t_token *token, t_data *data);
void	exec_builtin(t_token *token, t_data *data);

// Built-ins
int		echo(t_token *token);
void	exit_builtin(t_token *token);
void	pwd(void);
void	cd(t_token *token);
void	env(t_data *data);
void	export(t_token *token, t_data *data);
void	unset(t_token *token, t_data *data);

// Pipes
void	create_pipes(t_data *data);
void	close_pipes(t_data *data);
void	set_pipe_fd_in_token(t_token *token, t_data *data);
void	free_pipe_fd(t_token *token, t_data *data);

// Redirections
void	set_redirect_fd_in_token(t_token *token);
void	set_input_redirect(t_token *token);
void	set_heredoc_redirect(t_token *token);
void	set_output_redirect(t_token *token);
void	set_append_redirect(t_token *token);
void	close_redirect_files(t_token *token);

// Signals Aless
// void	ft_sigINGORE_handler(int signum);
// void	ft_sigINT_handler(int signum);
// int		ft_init_signal(int signum, void(*handler)(int));

// Signals
void	set_termios(void);
void	init_signal(void (*signal_handler)(int));
void	prompt_handler(int sig);
void	exec_handler(int sig);

#endif
