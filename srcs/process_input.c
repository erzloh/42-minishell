/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:08:43 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/02 17:16:52 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_input(char *input, t_data *data)
{
	(void) input; // Unused for now
	// Parsing
	// Check syntax errors
	// Create tokens
	// I'm creating tokens manually for testing purposes
	// The following is supposed to be in a "create_token()" or "fill_token()" function
	t_token	token;
	t_token	token2;
	// char	*cmd_arr[] = {"echo", "-n", "bonjour", "monsieur", NULL};
	char	*cmd_arr[] = {"ls", "-l", NULL};

	token.cmd_arr = cmd_arr;
	token.cmd_valid = 0;
	token.is_builtin = 0;
	token.infile_fd = STDIN_FILENO;
	token.outfile_fd = STDOUT_FILENO;
	token.pid = 0;
	token.id = 0;
	token.next = &token2;

	char	*cmd_arr2[] = {"cat", "-e", NULL};
	token2.cmd_arr = cmd_arr2;
	token2.cmd_valid = 0;
	token2.is_builtin = 0;
	token2.infile_fd = STDIN_FILENO;
	token2.outfile_fd = STDOUT_FILENO;
	token2.id = 1;
	token2.next = NULL;

	set_cmd_path_in_all_token(&token, data->env_arr);
	// Execute 
	executor(&token, data);
	return (0);
}
