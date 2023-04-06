/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:12:40 by eric              #+#    #+#             */
/*   Updated: 2023/04/06 10:04:11 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	create_pipes()
// int	create_children()

// Print a default error message and append the first argument to it.
// Print the errno error message as well.
// Return the second argument.
int	print_error(char *err_msg, int ret_val)
{
	char	*err_msg_default;
	char	*err_msg_full;

	err_msg_default = "An error occurred when trying to ";
	err_msg_full = ft_strjoin(err_msg_default, err_msg);
	perror(err_msg_full);
	free(err_msg_full);
	return (ret_val);
}

int	multiple_pipe(char ***cmd_arr_arr)
{
	int	i;
	int	j;
	int	pipe_nb = 0;
	int	pipe_fd[pipe_nb][2];
	int	pid;
	int	children_nb;

	children_nb = pipe_nb + 1;
	// Create the pipes
	i = 0;
	while (i < pipe_nb)
	{
		if (pipe(pipe_fd[i]) < 0)
			return (print_error("to create a pipe", 1));
		i++;
	}
	// Create the children processes
	i = 0;
	while (i < children_nb)
	{
		pid = fork();
		if (pid < 0)
			return (print_error("fork", 1));
		// Child process
		if (pid == 0)
		{
			// Redirect standard input
			if (i != 0)
				if (dup2(pipe_fd[i - 1][0], STDIN_FILENO) < 0)
					return (print_error("dup2() to redirect stdin", 1));
			// Redirect standard output
			if (i < children_nb - 1)
				if (dup2(pipe_fd[i][1], STDOUT_FILENO) < 0)
					return (print_error("dup2() to redirect stdout", 1));
			// Close all the pipes in the child
			j = 0;
			while (j < pipe_nb)
			{
				close(pipe_fd[j][0]);
				close(pipe_fd[j][1]);
				j++;
			}
			// Execute the command
			execve(cmd_arr_arr[i][0], cmd_arr_arr[i], NULL);
			// Should never reach here
			return (print_error("execute a command", 1));
		}
		i++;
	}
	// Close all the pipes in the parent
	i = 0;
	while (i < pipe_nb)
	{
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
		i++;
	}
	// Wait for all the children to terminate
	i = -1;
	while (++i < pipe_nb)
		wait(NULL);
	return (0);
}

int	main()
{
	char *cmd1_arr[] = {"/bin/echo", "-z", "hello", NULL};
	// char *cmd2_arr[] = {"/usr/bin/grep", "pipe", NULL};
	// char *cmd3_arr[] = {"/usr/bin/wc", "-l", NULL};
	// char **cmd_arr_arr[] = { cmd1_arr, cmd2_arr, cmd3_arr };
	char **cmd_arr_arr[] = { cmd1_arr };

	multiple_pipe(cmd_arr_arr);
}
