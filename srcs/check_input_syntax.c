/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:58:17 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/22 17:28:01 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/tokenizer.h"
#include "../incl/check_input_syntax.h"
#include "../incl/quote_manager.h"
#include "minishell.h"

bool	ft_is_empty_cmd(char *input)
{
	int	i;
	int	len;

	if (!input || !(*input))
		return (true);
	len = ft_strlen(input);
	if (!len)
		return (true);
	i = 0;
	while (input[i] && ft_is_white_space(input[i]))
		i++;
	if (i == len)
		return (true);
	return (false);
}

void	ft_print_syntax_error(char *token_error)
{
	printf("minishell: syntax error near unexpected token `%s'\n", token_error);
}

bool	ft_is_valid_pipe(char **f_input, int i)
{
	int	len;

	if (!f_input || !*f_input[i] || !ft_is_pipe(*f_input[i]))
		return (false);
	len = ft_str_arr_len(f_input);
	if (i == 0
		|| (i < len - 1 && ft_is_pipe(*f_input[i + 1]))
		|| i == len - 1)
	{
		ft_print_syntax_error("|");
		return (false);
	}
	return (true);
}

bool	ft_is_valid_redirection(char **f_input, int i)
{
	int		len;
	int		cnt_red_in_a_row;
	char	redirection;

	if (!f_input || !*f_input[i] || !ft_is_redirection(*f_input[i]))
		return (false);
	redirection = *f_input[i];
	len = ft_str_arr_len(f_input);
	cnt_red_in_a_row = 1;
	while (++i < len)
	{
		if (!ft_is_redirection(*f_input[i]) && !ft_is_pipe(*f_input[i]))
			return (true);
		if (ft_is_pipe(*f_input[i]))
			return (ft_print_syntax_error("|"), false);
		cnt_red_in_a_row++;
		if (ft_is_too_many_redirects(f_input, i, len, cnt_red_in_a_row))
			return (false);
		if (!ft_is_same_redirection(*f_input[i], redirection))
			return (false);
	}
	ft_print_syntax_error("newline");
	return (false);
}

bool	ft_is_correct_syntax(char *input)
{
	int		i;
	char	**format_input;

	if (ft_is_empty_cmd(input))
		return (false);
	if (check_unmatched_quotes(input))
		return (g_status = 258, false);
	format_input = ft_lexer(input);
	if (!format_input)
		return (ft_free_2d_char(format_input), g_status = 258, false);
	i = -1;
	while (format_input[++i])
	{
		if (ft_is_pipe(format_input[i][0]))
		{
			if (!ft_is_valid_pipe(format_input, i))
				return (ft_free_2d_char(format_input), g_status = 258, false);
		}
		else if (ft_is_redirection(format_input[i][0]))
		{
			if (!ft_is_valid_redirection(format_input, i))
				return (ft_free_2d_char(format_input), g_status = 258, false);
		}
	}
	return (ft_free_2d_char(format_input), true);
}
