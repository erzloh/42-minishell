/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:08:43 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/09 12:36:39 by eholzer          ###   ########.fr       */
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
	t_token	*token1 = malloc(sizeof(t_token));
	t_token	*token2 = malloc(sizeof(t_token));
	// char	*cmd_arr[] = {"echo", "-n", "bonjour", "monsieur", NULL};
	// char	*cmd_arr[] = {"grep", "Download", NULL};
	// char	*cmd_arr[] = {"cat", "-e", NULL};
	// char	*cmd_arr[] = {"exit", "42", NULL};
	// char	*cmd_arr[] = {"pwd", NULL};
	// char	*cmd_arr[] = {"cd", NULL};
	char	*cmd_arr[] = {"export", "bonjour", NULL};
	init_token(token1);
	token1->cmd_arr = cmd_arr;
	// token1->redirect.r_in_type s= HEREDOC_REDIRECT;
	// token1->redirect.infile = "EOF";
	// token1->next = token2;

	// char	*cmd_arr2[] = {"wc", "-l", NULL};
	// char	*cmd_arr2[] = {"echo", "bonjour", NULL};
	// char	*cmd_arr2[] = {"pwd", NULL};
	// char	*cmd_arr2[] = {"cat", "-e", NULL};
	// char	*cmd_arr2[] = {"exit", "42", NULL};
	char	*cmd_arr2[] = {"env", NULL};
	token2->cmd_arr = cmd_arr2;
	init_token(token2);

	set_cmd_path_in_all_token(token1, data->env_arr);
	set_cmd_path_in_all_token(token2, data->env_arr);
	// Execute 
	executor(token1, data);
	// executor(token2, data);
	executor(token2, data);
	return (0);
}
