/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:08:43 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/01 17:53:32 by eholzer          ###   ########.fr       */
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
	char	*cmd_arr[] = {"echo", "-n", "bonjour", "monsieur", NULL};
	// char	*cmd_arr[] = {"ls", "-z", NULL};

	token.cmd_arr = cmd_arr;
	token.cmd_valid = 0;
	token.is_builtin = 0;
	token.next = NULL;
	set_cmd_path(&token, data->env_arr);
	// Execute 
	executor(&token, data);
	return (0);
}
