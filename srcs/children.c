/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:58:14 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/19 16:25:31 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"
#include "env_utils.h"

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
			// Check if command is valid
			if (!token->is_valid_cmd && !token->is_builtin)
			{
				if (ft_find_index_env("PATH", data->envp_cpy) == -1)
					printf("minishell: %s: No such file or directory\n", token->cmd_arr[0]);
				else
					printf("minishell: %s: command not found\n", token->cmd_arr[0]);
				exit(127);
			}
			check_infile(token, data);
			set_dups(token);
			clean_up(token, data);
			if (token->is_builtin)
				exec_builtin(token, data);
			else
				exec_external(token, data);
		}
		token = token->next;
	}
}

void	check_infile(t_token *token, t_data *data)
{
	if (!token->redirect.is_valid_infile)
	{
		printf("minishell: %s: No such file or directory\n",
			token->redirect.infile);
		clean_up(token, data);
		exit(1);
	}
}

void	set_dups(t_token *token)
{
	if (dup2(token->redirect.infile_fd, STDIN_FILENO) < 0)
		fatal_error("Error with dup2() when redirecting stdin");
	if (dup2(token->redirect.outfile_fd, STDOUT_FILENO) < 0)
		fatal_error("Error with dup2() when redirecting stdout");
}

void	clean_up(t_token *token, t_data *data)
{
	close_pipes(data);
	close_redirect_files(token);
	free_pipe_fd(token, data);
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
		}
		token = token->next;
	}
}
