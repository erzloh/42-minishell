/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:55:13 by alesspal          #+#    #+#             */
/*   Updated: 2023/04/27 10:34:34 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H
# include "../libft/libft.h"

typedef struct s_token
{
	char			**cmd_arr;
	char			*cmd_path;
	char			*infile;
	char			*outfile;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

#endif