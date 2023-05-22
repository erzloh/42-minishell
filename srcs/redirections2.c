/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:12:14 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/22 16:39:41 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_redirect_files(t_token *token)
{
	while (token)
	{
		if (token->redirect.r_in_type == INPUT_REDIRECT
			&& token->redirect.is_valid_infile == true)
			if (close(token->redirect.infile_fd) < 0)
				fatal_error("Error when trying to close an in-file");
		if (token->redirect.r_out_type == OUTPUT_REDIRECT
			|| token->redirect.r_out_type == APPEND_REDIRECT)
			if (close(token->redirect.outfile_fd) < 0)
				fatal_error("Error when trying to close an out-file");
		token = token->next;
	}
}

void	set_append_redirect(t_token *token)
{
	char	*outfile;
	int		outfile_fd;

	outfile = token->redirect.outfile;
	outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (outfile_fd < 0)
		fatal_error("Error when openning an outfile");
	token->redirect.outfile_fd = outfile_fd;
}
