/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:29:17 by alesspal          #+#    #+#             */
/*   Updated: 2023/04/10 13:11:28 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/tokenizer.h"

t_token	*create_token(void)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
	{
		perror("ERROR : memory allocation failed");
		return (NULL);
	}
	new_token->next = NULL;
	new_token->cmd = NULL;
	new_token->arg = NULL;
	return (new_token);
}

void	ft_free_token(t_token *token)
{
	t_token *next;

	while (token)
	{
		next = token->next;
		if (token->cmd)
			free(token->cmd);
		if (token->arg)
			free(token->arg);
		if (token->flag)
			free(token->flag);
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
		ft_printf("cmd = %s\n", token->cmd);
		ft_printf("arg = %s\n", token->arg);
		ft_printf("flag = %s\n", token->flag);
		token = token->next;
	}
}
