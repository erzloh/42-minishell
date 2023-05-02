/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:55:13 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/02 16:58:35 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H
# include "../libft/libft.h"

typedef struct s_token
{
	char			**cmd_arr;
	char			*infile;
	char			*outfile;
	int				infile_fd;
	int				outfile_fd;
	int				cmd_valid;
	int				is_builtin;
	int				pid;
	int				id;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

#endif