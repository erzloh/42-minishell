/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:55:13 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/23 13:58:36 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

typedef enum e_redirect_in
{
	NO_R_IN,
	INPUT_REDIRECT,
	HEREDOC_REDIRECT
}	t_redirect_in;

typedef enum e_redirect_out
{
	NO_R_OUT,
	OUTPUT_REDIRECT,
	APPEND_REDIRECT
}	t_redirect_out;

typedef struct s_redirect
{
	char			*infile;
	char			*outfile;
	int				infile_fd;
	int				outfile_fd;
	int				is_valid_infile;
	int				*heredoc_pipe;
	t_redirect_in	r_in_type;
	t_redirect_out	r_out_type;
}	t_redirect;

typedef struct s_token
{
	char			**cmd_arr;
	int				is_valid_cmd;
	int				is_builtin;
	t_redirect		redirect;
	int				pid;
	int				id;
	struct s_token	*next;
}	t_token;

char	**ft_lexer(char const *s);
char	**ft_expander(char **line_elem, char **envp_copy);
t_token	*ft_init_token(int id);
int		ft_create_token(t_token **token, char **formatted_input);
void	ft_display_token(t_token *token);
void	ft_free_token(t_token *token);

#endif