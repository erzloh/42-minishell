/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:55:13 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/03 13:16:15 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

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
	int				id;
	char			**cmd_arr;
	bool			cmd_isvalid;
	bool			is_builtin;
	t_IO			io;
	int				pid;
	struct s_token	*next;
}	t_token;

t_token	*ft_create_token(int id);

#endif