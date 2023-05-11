/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:08:43 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/11 15:59:17 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_input(t_data *data)
{
	int	i;
	// Check syntax errors
	// Parsing
	data->formatted_input = ft_lexer(data->input);
	data->formatted_input = ft_expander(data->formatted_input, data->envp_cpy);
	data->tokens_nb = ft_create_token(&data->token, data->formatted_input);

	printf("formatted_input = {");
	i = -1;
	while (data->formatted_input[++i])
		printf("%s, ", data->formatted_input[i]);
	printf("}\n");
	/* printf("here\n"); */
	ft_display_token(data->token);

	// Create tokens
	// I'm creating tokens manually for testing purposes
	// The following is supposed to be in a "create_token()" or "fill_token()" function

	// t_token	*token1 = malloc(sizeof(t_token));
	// t_token	*token2 = malloc(sizeof(t_token));
	// t_token	*token3 = malloc(sizeof(t_token));
	// t_token	*token4 = malloc(sizeof(t_token));
	
	// char	*cmd_arr[] = {"echo", "-n", "bonjour", "monsieur", NULL};
	// char	*cmd_arr[] = {"grep", "Download", NULL};
	// char	*cmd_arr[] = {"cat", "-e", NULL};
	// char	*cmd_arr[] = {"exit", "42", NULL};
	// char	*cmd_arr[] = {"pwd", NULL};
	// char	*cmd_arr[] = {"cd", NULL};
	// char	*cmd_arr[] = {"export", "bonjour=42", NULL};
	// char	*cmd_arr[] = {"unset", "PATH", NULL};
	// char	*cmd_arr[] = {"ls", NULL};

	// char	*cmd_arr[] = {"export", "PATH=bonjour", NULL};
	// init_token(token1);
	// token1->cmd_arr = cmd_arr;
	
	// // token1->redirect.r_in_type s= HEREDOC_REDIRECT;
	// // token1->redirect.infile = "EOF";
	// // token1->next = token2;

	// // char	*cmd_arr2[] = {"wc", "-l", NULL};
	// // char	*cmd_arr2[] = {"echo", "bonjour", NULL};
	// // char	*cmd_arr2[] = {"pwd", NULL};
	// // char	*cmd_arr2[] = {"cat", "-e", NULL};
	// // char	*cmd_arr2[] = {"exit", "42", NULL};
	
	// char	*cmd_arr2[] = {"ls", NULL};
	// token2->cmd_arr = cmd_arr2;
	// init_token(token2);
	// // token2->next = token3;

	// // char	*cmd_arr3[] = {"unset", "bonjour", NULL};
	// char	*cmd_arr3[] = {"env", NULL};
	// token3->cmd_arr = cmd_arr3;
	// init_token(token3);

	// char	*cmd_arr4[] = {"env", NULL};
	// token4->cmd_arr = cmd_arr4;
	// init_token(token4);

	// Execute 
	// set_cmd_path_in_all_token(data->token, data->envp_cpy);
	// executor(data->token, data);

	// set_cmd_path_in_all_token(token1, data->envp_cpy);
	// executor(token1, data);
	
	// set_cmd_path_in_all_token(token2, data->envp_cpy);
	// executor(token2, data);
	
	// set_cmd_path_in_all_token(token3, data->envp_cpy);
	// executor(token3, data);
	
	// executor(token4, data);
	// set_cmd_path_in_all_token(token4, data->caca);
	return (0);
}
