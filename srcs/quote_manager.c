/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:39:00 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/15 17:15:05 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/quote_manager.h"

bool	check_unmatched_quotes(char *str)
{
	int	open_quote;

	open_quote = 0;
	while (str && *str)
	{
		if (!open_quote && (*str == '\'' || *str == '\"'))
			open_quote = *str;
		else if (*str == open_quote)
			open_quote = 0;
		str++;
	}
	if (open_quote)
	{
		ft_printf ("Error : quote open\n");
		return (true);
	}
	return (false);
}

void	update_quote_status(char cur_char, char *cur_quote)
{
	if (!*cur_quote && (cur_char == '\'' || cur_char == '\"'))
		*cur_quote = cur_char;
	else if (cur_char == *cur_quote)
		*cur_quote = 0;
}

char	*ft_remove_quotes(char *str)
{
	char	*result;
	int		i;
	int		j;
	char	open_quote;

	if (!str)
		return (NULL);
	result = (char *)malloc(ft_strlen(str) + 1);
	if (!result)
		ft_fatal_error("memory allocation error", E_ERROR_MALLOC);
	i = -1;
	j = 0;
	open_quote = 0;
	while (str[++i])
	{
		if ((str[i] == '\"' || str[i] == '\'') && !open_quote)
			open_quote = str[i];
		else if (str[i] == open_quote)
			open_quote = 0;
		else
			result[j++] = str[i];
	}
	result[j] = '\0';
	free(str);
	return (result);
}
