/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:58:17 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/12 14:03:50 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

bool	ft_is_empty_cmd(char *input)
{
	int	i;
	int	len;

	if (!input)
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

bool	ft_is_correct_syntax(char *input)
{
	
	if (check_unmatched_quotes(input))
		return (false);
	return (true);
}
