/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:51:07 by alesspal          #+#    #+#             */
/*   Updated: 2023/04/27 10:24:50 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*input;

	(void) ac;
	(void) av;
	(void) envp; // Unused for now
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
		{
			printf("An error occured with the input. ");
			printf("The program will now exit.\n");
			return (1);
		}
		add_history(input);
		process_input(input);
		free(input);
		// rl_on_new_line()
	}
	return (0);
}
