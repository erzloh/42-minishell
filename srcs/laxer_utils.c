/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laxer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:23:04 by alesspal          #+#    #+#             */
/*   Updated: 2023/04/10 15:03:25 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/tokenizer.h"

int	ft_is_pipe_or_red(int c)
{
	return (c == '|' || c == '<' || c == '>');
}

bool	is_command_end(char *input, int index)
{
	static int	is_pipe;
	static char	is_red;
	char		cur_char;

	cur_char = input[index];
	if (cur_char == '\0' || cur_char == ' '
		|| (index > 0 && cur_char == '|')
		|| (index > 0 && !is_red && (cur_char == '<' || cur_char == '>')))
	{
		is_pipe = 0;
		is_red = 0;
		return (true);
	}
	if (input[index] == '|')
		is_pipe = 1;
	else if (input[index] == '<' || input[index] == '>')
		is_red = input[index];
	if ((is_pipe && cur_char != '|')
		|| (is_red && cur_char != '<' && cur_char != '>'))
	{
		is_pipe = 0;
		is_red = 0;
		return (true);
	}
	return (false);
}

char	*ft_get_cmd(char *input, int *index)
{
	int			i;
	int			j;
	char		*strcmd;

	i = *index;
	if (!input || !input[i])
		return (NULL);
	while (input[i] && ft_is_white_space(input[i]))
		i++;
	j = 0;
	while (!is_command_end(input + i, j))
		j++;
	strcmd = ft_strndup(input + i, j);
	*index = i + j;
	return (strcmd);
}

char	*ft_get_flag(char *input, int *index)
{
	int		i;
	char	*strflag;

	i = *index;
	if (!input)
		return (NULL);
	while (input[i] && ft_is_white_space(input[i]))
		i++;
	if (ft_memcmp(input + i, "-n ", 3))
		return (ft_calloc(1, sizeof(char)));
	strflag = ft_strndup(input + i, 2);
	if (!strflag)
		return (NULL);
	*index = i + 2;
	return (strflag);
}

char	*ft_get_arg(char *inp, int *index)
{
	int		i;
	int		j;
	char	cur_quote;
	char	*arg;

	i = *index;
	if (!inp)
		return (NULL);
	while (inp[i] && ft_is_white_space(inp[i]))
		i++;
	j = -1;
	cur_quote = 0;
	while (inp[i + ++j] && (cur_quote != 0 || !ft_is_pipe_or_red(inp[i + j])))
	{
		if (!cur_quote && (inp[i + j] == '\'' || inp[i + j] == '\"'))
			cur_quote = inp[i + j];
		else if (inp[i + j] == cur_quote)
			cur_quote = 0;
	}
	if (j == 0)
		arg = ft_calloc(1, sizeof(char));
	else
		arg = ft_strndup(inp + i, j);
	*index = i + j;
	return (arg);
}
