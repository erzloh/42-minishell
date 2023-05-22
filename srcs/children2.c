/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:43:33 by eric              #+#    #+#             */
/*   Updated: 2023/05/22 15:59:01 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_utils.h"

// Returns 0 if the command is exit or cd and that there are no pipes
int	is_cmd_childable(t_token *token)
{
	if (!token->cmd_arr)
		return (1);
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

void	check_cmd_validity(t_token *token, t_data *data)
{
	if (!token->is_valid_cmd && !token->is_builtin)
	{
		if (ft_find_index_env("PATH", data->envp_cpy) == -1)
			printf("minishell: %s: No such file or directory\n",
				token->cmd_arr[0]);
		else
			printf("minishell: %s: command not found\n", token->cmd_arr[0]);
		exit(127);
	}
}
