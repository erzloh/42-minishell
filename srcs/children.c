/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:58:14 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/02 17:17:44 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int g_status;

// Creates children with fork() for each token element
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
			// set_dups
			if (dup2(token->infile_fd, STDIN_FILENO) < 0)
				fatal_error("Error with dup2() when redirecting stdin");
			if (dup2(token->outfile_fd, STDOUT_FILENO) < 0)
				fatal_error("Error with dup2() when redirecting stdout");
			// close_pipes
			close_pipes(data);
			if (token->is_builtin)
				exec_builtin(token, data);
			else
				exec_external(token, data);
		}
		token = token->next;
	}
}

// Executes with execve() the external command given by token
int	exec_external(t_token *token, t_data *data)
{
	if (token->cmd_valid)
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
	(void) data;
	if (ft_strncmp(token->cmd_arr[0], "echo", 5) == 0)
		echo(token);
}

// Waits that all the children finish their execution
void	wait_children(t_token *token)
{
	int	status;

	while (token)
	{
		waitpid(token->pid, &status, 0);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
			g_status = status;
			// printf("g_status = %d\n", g_status);
		}
		token = token->next;
	}
}
