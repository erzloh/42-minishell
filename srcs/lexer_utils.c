/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:06:33 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/22 16:51:44 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/lexer_utils.h"

int	ft_is_pipe_or_redirec(int c)
{
	return (c == '|' || c == '<' || c == '>');
}

void	update_word_count(const char *str, int i, int *nb_word)
{
	if ((i > 0 && ft_is_white_space(str[i]) && !ft_is_white_space(str[i - 1])
			&& !ft_is_pipe_or_redirec(str[i - 1]))
		|| ft_is_pipe_or_redirec(str[i]))
	{
		(*nb_word)++;
		if (i > 0 && ft_is_pipe_or_redirec(str[i])
			&& !ft_is_pipe_or_redirec(str[i - 1])
			&& !ft_is_white_space(str[i - 1]))
			(*nb_word)++;
	}
}

char	*create_word_and_update_start(const char *str, int i, int *start)
{
	int		length;
	char	*word;

	length = i - *start;
	if (length > 0)
	{
		word = ft_strndup(str + *start, length);
		if (!word)
			ft_fatal_error("memory allocation error\n", E_ERROR_MALLOC);
		*start = i;
	}
	else
	{
		word = ft_strndup(str + *start, 1);
		if (!word)
			ft_fatal_error("memory allocation error\n", E_ERROR_MALLOC);
		*start = i + 1;
	}
	return (word);
}

char	*handle_character(const char *str, int i, int *start)
{
	if (ft_is_pipe_or_redirec(str[i]) || ft_is_white_space(str[i]))
		return (create_word_and_update_start(str, i, start));
	else
		return (NULL);
}
