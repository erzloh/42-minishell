/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:55:13 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/08 16:29:41 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H
# include "../libft/libft.h"

typedef enum e_redirect_in
{
	INPUT_REDIRECT,		// <
	HEREDOC_REDIRECT,	// <<
	NO_R_IN
}	t_redirect_in;

typedef enum e_redirect_out
{
	OUTPUT_REDIRECT,	// >
	APPEND_REDIRECT,	// >>
	NO_R_OUT
}	t_redirect_out;

typedef struct s_redirect
{
	char			*infile;
	char			*outfile;
	int				infile_fd;
	int				outfile_fd;
	int				valid_infile;
	int				*heredoc_pipe;
	t_redirect_in	r_in_type;
	t_redirect_out	r_out_type;
}	t_redirect;

#include "../libft/libft.h"
#include "minishell.h"

typedef struct s_IO
{
	char			*infile;
	char			*outfile;
	int				infile_fd;
	int				outfile_fd;
}	t_IO;

typedef struct s_token
{
	char			**cmd_arr;
	int				valid_cmd;
	int				is_builtin;
	t_redirect		redirect;
	int				pid;
	struct s_token	*next;
}	t_token;

t_token	*create_token(void);
void	ft_free_token(t_token *token);
void	ft_display_token(t_token *token);

// laxer
t_token		*ft_laxing_cmd(char *input);
int			ft_is_pipe_or_red(int c);
char		*ft_get_cmd(char *input, int *index);
char		*ft_get_arg(char *input, int *index);
char		*ft_get_flag(char *input, int *index);

// checkers
char		*ft_find_and_check_echo_arg(char *arg, int *index);
char		*ft_find_and_check_cd_arg(char *input, int *index);
bool		check_unmatched_quotes(char *str);

// expender
t_token		*ft_expend_cmd(t_token *token);
char		*ft_remove_quotes(char *str);
char		*ft_strtrim_minishell(char *src);

#endif