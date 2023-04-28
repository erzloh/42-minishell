/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:49:54 by eholzer           #+#    #+#             */
/*   Updated: 2023/04/28 10:25:26 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	executor(t_token *token, t_data *data)
{
	exec_single_cmd(token, data);
	return (0);
}

int	exec_single_cmd(t_token *token, t_data *data)
{
	if (token->cmd_valid)
	{
		execve(token->cmd_arr[0], token->cmd_arr, data->env_arr);
		printf("minishell: %s: is a directory\n", token->cmd_arr[0]);
	}
	else
		printf("minishell: %s: command not found\n", token->cmd_arr[0]);
	// exit(1);
	return (1);
}
