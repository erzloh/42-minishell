/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:51:07 by alesspal          #+#    #+#             */
/*   Updated: 2023/04/25 12:01:45 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	main()
{
	char	*input;
	if (isatty(STDIN_FILENO))				// check if is interactive environment
	{
		while (1)
		{
			input = readline("$ ");			// write "$ " and waits an input and read it
			if (!input)
				break;
			add_history(input);				// function for retrieving written commands
			ft_execute_cmd(input);			// execute the command
			free(input);
			rl_on_new_line();
		}
	}
	return (0);
}

// int main() {
//     char *argv[] = { "ls", "-l", NULL };
//     char *envp[] = { "MYVAR=hello", NULL };
//     execve("/bin/ls", argv, envp);
//     perror("execve"); // This line will be executed only if execve fails
//     return 0;
// }