/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:51:07 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/13 16:05:05 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// test
int	main()
{
	char	*input;

	while (1)
	{
		input = readline("$ "); // read input after "$ "
		if (input)
		{
			add_history(input); // function for retrieving written commands
			// execute the command
			free(input);
		}
		else
		{
			printf("Erreur : %s\n", strerror(errno));
			break ;
		}
	}
	return (0);
}