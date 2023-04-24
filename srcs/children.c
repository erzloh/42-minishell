/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:37:30 by eholzer           #+#    #+#             */
/*   Updated: 2023/04/24 08:57:00 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Executes the child's command
// Handles stdin and stdout redirections in cases of pipes and closes them
int	exec_child(int pipes_nb, int **pipe_fd, char ***cmds_arr, int i)
{
	int	children_nb;

	children_nb = pipes_nb + 1;
	// Redirect standard input
	if (i != 0)
		if (dup2(pipe_fd[i - 1][0], STDIN_FILENO) < 0)
			return (print_error("dup2() to redirect stdin", -1));
	// Redirect standard output
	if (i < children_nb - 1)
		if (dup2(pipe_fd[i][1], STDOUT_FILENO) < 0)
			return (print_error("dup2() to redirect stdout", -1));
	// Close all the pipes in the child
	if (close_pipes(pipes_nb, pipe_fd) == -1)
		return (-1);
	// Execute the command
	execve(cmds_arr[i][0], cmds_arr[i], NULL);
	// Should never reach here
	return (print_error("execute a command", -1));
}

// Creates pipes_nb + 1 children with fork()
int	create_children(int pipes_nb, int **pipe_fd, char ***cmds_arr)
{
	int	pid;
	int	i;
	int	children_nb;

	children_nb = pipes_nb + 1;
	i = 0;
	while (i < children_nb)
	{
		pid = fork();
		if (pid < 0)
			return (print_error("fork", 1));
		// Child process
		if (pid == 0)
		{
			if (exec_child(pipes_nb, pipe_fd, cmds_arr, i) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

// Waits that all the children finish their execution
void	wait_children(t_token *token)
{
	int	i;
	int	children_nb;

	i = -1;
	children_nb = token->pipes_nb + 1;
	while (++i < children_nb)
		wait(NULL);
}
