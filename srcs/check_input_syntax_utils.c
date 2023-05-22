/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_syntax_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:32:56 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/22 15:16:21 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/check_input_syntax.h"

bool	ft_is_pipe(int c)
{
	return (c == '|');
}

bool	ft_is_redirection(int c)
{
	return (c == '<' || c == '>');
}

bool	ft_is_too_many_redirects(char **f_input, int i, int len, int cnt_red)
{
	char	*error;

	if (cnt_red < 3)
		return (false);
	if (i < len - 1 && ft_is_redirection(*f_input[i + 1]))
	{
		error = ft_strjoin(f_input[i], f_input[i + 1]);
		ft_print_syntax_error(error);
		free(error);
	}
	else
		ft_print_syntax_error(f_input[i]);
	return (true);
}

bool	ft_is_same_redirection(char cur_redirection, char prev_redirection)
{
	if (prev_redirection != cur_redirection)
	{
		ft_print_syntax_error(&cur_redirection);
		return (false);
	}
	return (true);
}
