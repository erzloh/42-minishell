/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:44:30 by eric              #+#    #+#             */
/*   Updated: 2023/04/21 14:38:08 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// ------- NOT USED ---------

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

int main()
{
	char *cmd_arr[] = {"/bin/echo", "bonjour", NULL};

	execute_cmd(cmd_arr);
	return 0;
}