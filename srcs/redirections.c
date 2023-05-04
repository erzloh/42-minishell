/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 08:59:43 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/04 12:11:03 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_redirect_fd_in_token(t_token *token)
{
	while (token)
	{
		if (token->redirect.r_in_type == INPUT_REDIRECT)
			set_input_redirect(token);
		else if (token->redirect.r_in_type == OUTPUT_REDIRECT)
			set_output_redirect(token);
		if (token->redirect.r_out_type == APPEND_REDIRECT)
			set_append_redirect(token);
		// else if (token->redirect.r_out_type == HEREDOC_REDIRECT)
			// set_heredoc_redirect(token);
		token = token->next;
	}
}

void	set_input_redirect(t_token *token)
{
	token->redirect.infile_fd = open(token->redirect.infile, O_RDONLY);
	if (token->redirect.infile_fd < 0)
		token->redirect.valid_infile = 0;
}

void	set_output_redirect(t_token *token)
{
	char	*outfile;
	int		outfile_fd;

	outfile = token->redirect.outfile;
	outfile_fd = open(outfile, O_WRONLY | O_CREAT);
	if (outfile_fd < 0)
		fatal_error("Error when openning an outfile");
	token->redirect.outfile_fd = outfile_fd;
}

void	set_append_redirect(t_token *token)
{
	char	*outfile;
	int		outfile_fd;

	outfile = token->redirect.outfile;
	outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_APPEND);
	if (outfile_fd < 0)
		fatal_error("Error when openning an outfile");
	token->redirect.outfile_fd = outfile_fd;
}

// void	close_redirect_files(t_token *token)
// {
	
// }
