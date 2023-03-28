/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:10:46 by eholzer           #+#    #+#             */
/*   Updated: 2023/03/28 16:05:19 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_simple_pipe(char **cmd1_arr, char **cmd2_arr)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) < 0)
	{
		perror("An error occurred when trying to open the pipe\n");
		return (1);
	}
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("An error occurred when trying to fork\n");
		return (1);
	}
	if (pid1 == 0)
	{
		// Child Process 1 (ls -l)
		dup2(fd[1], STDOUT_FILENO); // Redirects its output to the pipe
		close(fd[0]);
		close(fd[1]);
		execve(cmd1_arr[0], cmd1_arr, NULL);
		{
			perror("An error occurred when trying to call execve()");
			return (1);
		}
	}
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("An error occurred when trying to fork\n");
		return (1);
	}
	if (pid2 == 0)
	{
		// Child Process 2 (wc -l)
		dup2(fd[0], STDIN_FILENO); // Redirects its input to the pipe 
		close(fd[0]);
		close(fd[1]);
		execve(cmd2_arr[0], cmd2_arr, NULL);
		{
			perror("An error occurred when trying to call execve()");
			return (1);
		}
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

// int main()
// {
// 	char *cmd1_arr[] = {"/bin/ls", "-l", NULL};
// 	char *cmd2_arr[] = {"/usr/bin/wc", "-l", NULL};

// 	if (exec_simple_pipe(cmd1_arr, cmd2_arr) == 1)
// 		return (1);
// 	return (0);
// }
