/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _executor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:31:56 by eholzer           #+#    #+#             */
/*   Updated: 2023/04/24 11:44:59 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Executes the command line given by the token and its next elements.
// @param token A pointer to the first element of a token list.
// @return Returns 0 if there are no errors, 1 if there is one.
int	executor(t_token *token)
{
	char	***cmds_arr;
	int		**pipe_fd;
	int		error;

	complete_token(token);
	if (is_equal(token->cmd, "cd"))
		return (cd(token));
	error = create_pipes(&pipe_fd, token->pipes_nb);
	if (error != 0)
		return (error);
	cmds_arr = get_cmds_arr(token);
	if (!cmds_arr)
	{
		free_pipe_fd(pipe_fd, token->pipes_nb);
		return (print_error("to malloc cmds_arr", MALLOC_ERR));
	}
	if (create_children(token->pipes_nb, pipe_fd, cmds_arr) == -1)
	{
		free_memory(cmds_arr, pipe_fd, token->pipes_nb);
		return (1);
	}
	if (close_pipes(token->pipes_nb, pipe_fd) == -1)
	{
		free_memory(cmds_arr, pipe_fd, token->pipes_nb);
		return (1);
	}
	wait_children(token);
	free_memory(cmds_arr, pipe_fd, token->pipes_nb);
	return (0);
}
