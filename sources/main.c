/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:51:07 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/13 17:25:54 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
{
	char	*input;

	if (init_signal(SIGINT, sig_handler) || init_signal(SIGQUIT, SIG_IGN))
		return (0);
	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			input = readline("$ "); // write "$ " and waits an input and read it 
			if (input)
			{
				add_history(input); // function for retrieving written commands
				// execute the command
				free(input);
			}
			else
				break ;
		}
	}
	return (0);
}