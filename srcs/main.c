/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:51:07 by alesspal          #+#    #+#             */
/*   Updated: 2023/04/28 17:10:50 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*input;
	// t_data	*data; Will be initialized properly later
	t_data	data;

	(void) ac;
	(void) av;
	(void) envp; // Unused for now
	data.env_arr = NULL; // Set to NULL for now
	// init_data(data, envp);
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
		{
			printf("An error occured with the input. ");
			printf("The program will now exit.\n");
			// free the copy of envp and any allocated memory to exit in a clean manner
			return (1);
		}
		add_history(input);
		if (process_input(input, &data) == MALLOC_ERR)
		{
			// free_all(token, data, input); // Free the input, free the token and its attributes, free the env_arr, and basically everything that was malloced
			return (MALLOC_ERR);
		}
		free(input); // We can do free_all() here as well I guess
		// rl_on_new_line()
	}
	return (0);
}

// int	main()
// {
// 	t_token	token;
// 	char	**env_arr;
// 	char	*cmd_arr[] = {"/bin/ls", NULL};

// 	token.cmd_arr = cmd_arr;
// 	token.cmd_valid = 0;
// 	env_arr = NULL;
// 	// set_cmd_path(&token, env_arr);
// 	// printf("cmd = %s\n", token.cmd_arr[0]);
// 	// printf("cmd_valid = %i\n", token.cmd_valid);
// 	execve(token.cmd_arr[0], token.cmd_arr, env_arr);
// 	perror("Error: ");
// }
