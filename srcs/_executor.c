/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _executor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:31:56 by eholzer           #+#    #+#             */
/*   Updated: 2023/04/21 13:45:28 by eholzer          ###   ########.fr       */
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

	complete_token(token);
	if (create_pipes(&pipe_fd, token->pipes_nb) == -1)
		return (1);
	cmds_arr = get_cmds_arr(token);
	if (!cmds_arr)
		return (print_error("to malloc cmds_arr", 1));
	if (create_children(token->pipes_nb, pipe_fd, cmds_arr) == -1)
		return (1);
	if (close_pipes(token->pipes_nb, pipe_fd) == -1)
		return (1);
	wait_children(token);
	free_cmds_arr(cmds_arr);
	if (token->pipes_nb != 0)
		free_pipe_fd(pipe_fd);
	return (0);
}
