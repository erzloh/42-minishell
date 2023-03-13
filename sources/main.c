/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:51:07 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/13 14:53:20 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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