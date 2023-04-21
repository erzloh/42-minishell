/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laxer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:04:09 by alesspal          #+#    #+#             */
/*   Updated: 2023/04/10 15:36:43 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/tokenizer.h"

bool	process_token(t_token *token, char *input, int *i)
{
	token->cmd = ft_get_cmd(input, i);
	if (!token->cmd)
		return (false);
	if (!ft_memcmp(token->cmd, "|\0", 2))
	{
		token->arg = ft_calloc(1, sizeof(char));
		token->flag = ft_calloc(1, sizeof(char));
	}
	else
	{
		if (!ft_memcmp(token->cmd, "echo\0", 5))
		{
			token->flag = ft_get_flag(input, i);
			if (!token->flag)
				return (false);
		}
		else
			token->flag = ft_calloc(1, sizeof(char));
		token->arg = ft_get_arg(input, i);
		if (!token->arg)
			return (false);
	}
	return (true);
}

t_token	*ft_laxing_cmd(char *input)
{
	int		i;
	t_token	*head_token;
	t_token	*tail_token;

	if (!input)
		return (NULL);
	tail_token = create_token();
	if (!tail_token)
		return (NULL);
	head_token = tail_token;
	i = 0;
	if (check_unmatched_quotes(input))
		return (NULL);
	while (input[i])
	{
		if (!process_token(tail_token, input, &i))
			break ;
		if (!input[i])
			break ;
		tail_token->next = create_token();
		if (!tail_token->next)
			return (ft_free_token(head_token), NULL);
		tail_token = tail_token->next;
	}
	return (head_token);
}
