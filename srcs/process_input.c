/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:08:43 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/04 12:43:53 by eholzer          ###   ########.fr       */
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
	char	*cmd_arr[] = {"grep", "Download", NULL};

	token1->cmd_arr = cmd_arr;
	token1->valid_cmd = 0;
	token1->is_builtin = 0;
	token1->redirect.infile_fd = STDIN_FILENO;
	token1->redirect.outfile_fd = STDOUT_FILENO;
	token1->redirect.valid_infile = 1;
	token1->redirect.r_in_type = INPUT_REDIRECT;
	token1->redirect.r_out_type = NO_R_OUT;
	token1->redirect.infile = "test.c";
	token1->pid = 0;
	token1->id = 0;
	token1->next = token2;

	char	*cmd_arr2[] = {"wc", "-l", NULL};
	token2->cmd_arr = cmd_arr2;
	token2->valid_cmd = 0;
	token2->is_builtin = 0;
	token2->redirect.infile_fd = STDIN_FILENO;
	token2->redirect.outfile_fd = STDOUT_FILENO;
	token2->redirect.valid_infile = 1;
	token2->redirect.r_in_type = NO_R_IN;
	token2->redirect.r_out_type = NO_R_OUT;
	token2->id = 1;
	token2->next = NULL;

	set_cmd_path_in_all_token(token1, data->env_arr);
	// Execute 
	executor(token1, data);
	return (0);
}
