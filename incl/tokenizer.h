/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:55:13 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/05 10:03:47 by eholzer          ###   ########.fr       */
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

typedef struct s_token
{
	char			**cmd_arr;
	int				valid_cmd;
	int				is_builtin;
	t_redirect		redirect;
	int				pid;
	struct s_token	*next;
}	t_token;

#endif