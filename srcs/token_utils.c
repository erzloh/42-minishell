/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:16:46 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/29 10:23:09 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/tokenizer.h"

void	ft_free_token(t_token *token)
{
	t_token	*next;

	while (token)
	{
		next = token->next;
		if (token->arg)
			free(token->arg);
		free(token);
		token = next;
	}
}


void	ft_display_token(t_token *token)
{
	int	i;

	i = -1;
	while (token)
	{
		i++;
		ft_printf("token %i :\n", i);
		ft_printf("cmd = %i\n", token->cmd);
		ft_printf("arg = %s\n", token->arg);
		token = token->next;
	}
}
