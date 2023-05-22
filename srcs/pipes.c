/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:45:03 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/22 16:33:57 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Creates pipes
void	create_pipes(t_data *data)
{
	int	pipes_nb;
	int	i;

	pipes_nb = data->tokens_nb - 1;
	if (pipes_nb == 0)
		return ;
	data->pipe_fd = malloc(sizeof(int *) * pipes_nb);
	if (!data->pipe_fd)
		fatal_error("Error with malloc()");
	i = -1;
	while (++i < pipes_nb)
	{
		data->pipe_fd[i] = malloc(sizeof(int) * 2);
		if (!data->pipe_fd[i])
			fatal_error("Error with malloc()");
	}
	i = -1;
	while (++i < pipes_nb)
	{
		if (pipe(data->pipe_fd[i]) < 0)
			fatal_error("Error with pipe()");
	}
}

// Closes the write-end and the read-end of pipes
void	close_pipes(t_data *data)
{
	int		pipes_nb;
	int		i;
	t_token	*curr_token;

	pipes_nb = data->tokens_nb - 1;
	i = -1;
	while (++i < pipes_nb)
	{
		if (close(data->pipe_fd[i][0]) < 0)
			fatal_error("Error when closing the read-end of a pipe");
		if (close(data->pipe_fd[i][1]) < 0)
			fatal_error("Error when closing the write-end a pipe");
	}
	curr_token = data->token;
	while (curr_token)
	{
		if (curr_token->redirect.heredoc_pipe)
		{
			if (close(curr_token->redirect.heredoc_pipe[0]) < 0)
				fatal_error("Error when closing the read-end of a << pipe");
			if (close(curr_token->redirect.heredoc_pipe[1]) < 0)
				fatal_error("Error when closing the write-end a << pipe");
		}
		curr_token = curr_token->next;
	}
}

// Fills token->redirect.infile and outfile with the appropriate pipe fds
void	set_pipe_fd_in_token(t_token *token, t_data *data)
{
	int	i;

	i = 0;
	while (token)
	{
		if (i != 0)
			token->redirect.infile_fd = data->pipe_fd[i - 1][0];
		if (i < data->tokens_nb - 1)
			token->redirect.outfile_fd = data->pipe_fd[i][1];
		token = token->next;
		i++;
	}
}

// Frees the pipe fd for the regular pipes, and the heredoc pipes if they exists
void	free_pipe_fd(t_token *token, t_data *data)
{
	int	pipes_nb;
	int	i;

	pipes_nb = data->tokens_nb - 1;
	if (pipes_nb == 0)
		return ;
	i = -1;
	while (++i < pipes_nb)
		free(data->pipe_fd[i]);
	free(data->pipe_fd);
	while (token)
	{
		if (token->redirect.heredoc_pipe)
			free(token->redirect.heredoc_pipe);
		token = token->next;
	}
}
