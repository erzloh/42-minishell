/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:39:37 by eholzer           #+#    #+#             */
/*   Updated: 2023/04/21 11:50:26 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Returns the number of pipes in a token list.
int	get_pipes_nb(t_token *token)
{
	int	pipes_nb;

	pipes_nb = 0;
	while (token)
	{
		if (is_equal(token->cmd, "|") == 1)
			pipes_nb++;
		token = token->next;
	}
	return (pipes_nb);
}

// Creates pipes
int	create_pipes(int ***pipe_fd, int pipes_nb)
{
	int	i;

	i = 0;
	*pipe_fd = malloc(sizeof(int *) * pipes_nb);
	if (!(*pipe_fd))
		return (print_error("to malloc a pipe fd", -1));
	while (i < pipes_nb)
	{
		(*pipe_fd)[i] = malloc(sizeof(int) * 2);
		if (!(*pipe_fd)[i])
			return (print_error("to malloc a pipe", -1));
		i++;
	}
	i = 0;
	while (i < pipes_nb)
	{
		if (pipe((*pipe_fd)[i]) < 0)
			return (print_error("to create a pipe", -1));
		i++;
	}
	return (0);
}

// Closes the write-end and the read-end of pipes
// Should I protect the close calls?
int	close_pipes(int pipes_nb, int **pipe_fd)
{
	int	i;

	i = 0;
	while (i < pipes_nb)
	{
		if (close(pipe_fd[i][0] < 0))
			return (print_error("to close the read-end of a pipe", -1));
		if (close(pipe_fd[i][1] < 0))
			return (print_error("to close the write-end a pipe", -1));
		i++;
	}
	return (0);
}
