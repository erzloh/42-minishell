/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:12:14 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/05 09:12:22 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_redirect_files(t_token *token)
{
	while (token)
	{
		if (token->redirect.r_in_type == INPUT_REDIRECT)
			if (close(token->redirect.infile_fd) < 0)
				fatal_error("Error when trying to close an in-file");
		if (token->redirect.r_out_type == OUTPUT_REDIRECT
			|| token->redirect.r_out_type == APPEND_REDIRECT)
			if (close(token->redirect.outfile_fd) < 0)
				fatal_error("Error when trying to close an out-file");
		token = token->next;
	}
}
