/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:28:45 by alesspal          #+#    #+#             */
/*   Updated: 2023/04/21 15:57:28 by eholzer          ###   ########.fr       */
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

// executor
void	ft_execute_cmd(char *input);

// env
int		ft_setenv(const char *name, const char *value);
int		ft_unsetenv(char *name);
char	*ft_getenv(const char *name);
void	ft_get_all_env(void);

// env_utils
bool	ft_is_valid_name(const char *name);
int		ft_find_index_env(const char *name);
int		ft_replace_env(const char *name, const char *value);
int		ft_add_env(const char *name, const char *value);
char	**ft_copy_env_except(char *name);

// signal managemenent
void	ft_sigINGORE_handler(int sig);
void	ft_sigINT_handler(int signum);
int		ft_init_signal(int signum, void(*handler)(int));

// Eric's stuff
// --- Functions related to the executor --- 
int		executor(t_token *token);

// Children
int		create_children(int pipes_nb, int **pipe_fd, char ***cmds_arr);
int		exec_child(int pipes_nb, int **pipe_fd, char ***cmds_arr, int i);
void	wait_children(t_token *token);

// Pipes
int		get_pipes_nb(t_token *token);
int		create_pipes(int ***pipe_fd, int pipes_nb);
int		close_pipes(int pipe_nb, int **pipe_fd);

// cmds_arr functions
char	***get_cmds_arr(t_token *token);
int		fill_cmds_arr(char ***cmds_arr, t_token *token);
char	**get_cmd_arr(t_token *token, int i);
void	fill_cmd_arr(char ***cmd_arr, t_token *token);
int		get_cmd_arr_size(t_token *token);

// Command related utility functions
int		is_cmd(char *str);
int		get_cmds_nb(t_token *token);
char	*get_cmd_path(char *cmd);

// Utility functions
int		print_error(char *err_msg, int ret_val);
int		is_equal(const char *s1, const char *s2);
void	complete_token(t_token *token);

// Free functions
void	free_cmds_arr(char ***cmds_arr);
void	free_cmd_arr(char **cmd_arr);
void	free_pipe_fd(int **pipe_fd);
void	free_memory(char ***cmds_arr, int **pipe_fd, int pipes_nb);

#endif
