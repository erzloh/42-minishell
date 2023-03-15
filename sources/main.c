/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:51:07 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/15 09:11:41 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
{
	char	*input;

	if (isatty(STDIN_FILENO)) // check if is interactive environment
	{
		while (1)
		{
			input = readline("$ "); // write "$ " and waits an input and read it
			printf("input = %s\n", input);
			if (!input)
				break;
			add_history(input); // function for retrieving written commands
			// execute the command
			if (strcmp(input, "exit") == 0) // temporaire juste pour pouvoir quitter le code sans faire ctrl + c
			{
				exit(0);
				free(input);
			}
			free(input);
			rl_on_new_line();
		}
	}
	return (0);
}