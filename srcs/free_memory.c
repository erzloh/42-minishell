/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:12:04 by eholzer           #+#    #+#             */
/*   Updated: 2023/04/21 15:02:59 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd_arr(char **cmd_arr)
{
	int	i;

	i = 0;
	while (cmd_arr[i])
	{
		free(cmd_arr[i]);
		i++;
	}
	free(cmd_arr);
}

void	free_cmds_arr(char ***cmds_arr)
{
	int	i;

	i = 0;
	while (cmds_arr[i])
	{
		free_cmd_arr(cmds_arr[i]);
		i++;
	}
	free(cmds_arr);
}

void	free_pipe_fd(int **pipe_fd)
{
	int	i;

	i = 0;
	while (pipe_fd[i])
	{
		free(pipe_fd[i]);
		i++;
	}
	free(pipe_fd);
}

void	free_memory(char ***cmds_arr, int **pipe_fd, int pipes_nb)
{
	free_cmds_arr(cmds_arr);
	if (pipes_nb != 0)
		free_pipe_fd(pipe_fd);
}
