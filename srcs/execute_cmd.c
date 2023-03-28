/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:44:30 by eric              #+#    #+#             */
/*   Updated: 2023/03/28 15:44:35 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Takes an array of a command with its potential flags and arguments and
// execute it. The command must be written with its full path.
int	execute_cmd(char **cmd_arr)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
	{
		if (execve(cmd_arr[0], cmd_arr, NULL) == -1)
		{
			perror("Error with execve()");
			return (-1);
		}
	}
	else
	{
		wait(NULL);
		printf("command was successfully executed\n");
	}
	return (0);
}

// int main()
// {
// 	char *cmd_arr[] = {"/bin/ls", "-l", NULL};

// 	execute_cmd(cmd_arr);
// 	return 0;
// }