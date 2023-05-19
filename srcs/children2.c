/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:43:33 by eric              #+#    #+#             */
/*   Updated: 2023/05/17 10:21:52 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

// Returns 0 if the command is exit or cd and that there are no pipes
int	is_cmd_childable(t_token *token)
{
	if (ft_strncmp(token->cmd_arr[0], "exit", 5) == 0
		|| ft_strncmp(token->cmd_arr[0], "cd", 3) == 0
		|| ft_strncmp(token->cmd_arr[0], "unset", 6) == 0)
	{
		if (token->next == NULL)
			return (0);
	}
	else if (ft_strncmp(token->cmd_arr[0], "export", 7) == 0)
	{
		if (token->cmd_arr[1])
			return (0);
	}
	return (1);
}
