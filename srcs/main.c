/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:51:07 by alesspal          #+#    #+#             */
/*   Updated: 2023/04/27 16:44:42 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	main(int ac, char **av, char **envp)
// {
// 	char	*input;

// 	(void) ac;
// 	(void) av;
// 	(void) envp; // Unused for now
// 	while (1)
// 	{
// 		input = readline("minishell$ ");
// 		if (!input)
// 		{
// 			printf("An error occured with the input. ");
// 			printf("The program will now exit.\n");
// 			return (1);
// 		}
// 		add_history(input);
// 		process_input(input);
// 		free(input);
// 		// rl_on_new_line()
// 	}
// 	return (0);
// }

int	main()
{
	t_token	token;
	char	**env_arr;
	char	*cmd_arr[] = {"/sad/ads", "-l", NULL};

	token.cmd_arr = cmd_arr;
	token.cmd_valid = 0;
	env_arr = NULL;
	set_cmd_path(&token, env_arr);
	printf("cmd = %s\n", token.cmd_arr[0]);
	printf("cmd_valid = %i\n", token.cmd_valid);
}
