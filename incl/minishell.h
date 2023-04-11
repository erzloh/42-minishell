/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:28:45 by alesspal          #+#    #+#             */
/*   Updated: 2023/04/06 14:07:52 by alesspal         ###   ########.fr       */
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

#endif