/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:58:14 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/22 16:10:03 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Creates children with fork() for each token element
void	create_children(t_token *token, t_data *data)
{
	while (token)
	{
		token->pid = fork();
		if (token->pid < 0)
			fatal_error("Error with fork()");
		if (token->pid == 0)
		{
			check_infile(token, data);
			check_cmd_validity(token, data);
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
