/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:51:07 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/01 15:42:37 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status;

int	main(int ac, char **av, char **envp)
{
	char	*input;
	// t_data	*data; Will be initialized properly later
	t_data	data;

	(void) ac;
	(void) av;
	(void) envp; // Unused for now
	g_status = 0;
	data.env_arr = NULL; // Set to NULL for now
	// init_data(data, envp);
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			fatal_error("Error with readline()");
		add_history(input);
		process_input(input, &data);
		free(input); // We can do free_all() here as well I guess, to free the input, the token, etc...
		// rl_on_new_line()
		// printf("%d", g_status);
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
