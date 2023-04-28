/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:08:43 by eholzer           #+#    #+#             */
/*   Updated: 2023/04/28 10:22:30 by eholzer          ###   ########.fr       */
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
	char	*cmd_arr[] = {"clear", NULL};

	token.cmd_arr = cmd_arr;
	token.cmd_valid = 0;
	if (set_cmd_path(&token, data->env_arr) == MALLOC_ERR)
		return (MALLOC_ERR);

	// Execute
	executor(&token, data);
	return (0);
}
