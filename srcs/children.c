/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:58:14 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/01 15:08:49 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_children(t_token *token, t_data *data)
{
	while (token)
	{
		token->pid = fork();
		if (token->pid < 0)
			fatal_error("Error with fork()");
		// Child Process
		if (token->pid == 0)
		{
			if (is_builtin(token))
				exec_builtin(token, data);
			else
				exec_single_cmd(token, data);
		}
		token = token->next;
	}
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
	exit(1);
}

// Waits that all the children finish their execution
void	wait_children(t_token *token)
{
	while (token)
	{
		wait(NULL);
		token = token->next;
	}
}

void	exec_builtin(t_token *token, t_data *data)
{
	(void) data;
	if (ft_strncmp(token->cmd_arr[0], "echo", 5) == 0)
		echo(token);
}
