/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:44:30 by eric              #+#    #+#             */
/*   Updated: 2023/03/27 21:36:01 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Takes an array of a command with its potential flags and arguments and
// execute it. The command must be written with its full path.
int	execute_cmd(char **cmd)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
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
// 	char *cmd[] = {"/bin/ls", "-l", NULL};

// 	execute_cmd(cmd);
// 	return 0;
// }