/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:51:03 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/09 14:04:12 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Executes with execve() the external command given by token
int	exec_external(t_token *token, t_data *data)
{
	if (token->valid_cmd)
	{
		execve(token->cmd_arr[0], token->cmd_arr, data->env_arr);
		printf("minishell: %s: is a directory\n", token->cmd_arr[0]);
	}
	else
		printf("minishell: %s: command not found\n", token->cmd_arr[0]);
	exit(127);
}

// Executes the built-in command given by token
void	exec_builtin(t_token *token, t_data *data)
{
	if (ft_strncmp(token->cmd_arr[0], "echo", 5) == 0)
		echo(token);
	else if (ft_strncmp(token->cmd_arr[0], "exit", 5) == 0)
		exit_builtin(token);
	else if (ft_strncmp(token->cmd_arr[0], "pwd", 4) == 0)
		pwd();
	else if (ft_strncmp(token->cmd_arr[0], "cd", 3) == 0)
		cd(token);
	else if (ft_strncmp(token->cmd_arr[0], "env", 4) == 0)
		env(data);
	else if (ft_strncmp(token->cmd_arr[0], "export", 7) == 0)
		export(token, data);
	else if (ft_strncmp(token->cmd_arr[0], "unset", 6) == 0)
		unset(token, data);
}
