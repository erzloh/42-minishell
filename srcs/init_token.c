/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:39:07 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/05 10:04:04 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_token(t_token *token)
{
	token->is_builtin = 0;
	token->valid_cmd = 0;
	token->pid = 0;
	token->redirect.infile_fd = STDIN_FILENO;
	token->redirect.outfile_fd = STDOUT_FILENO;
	token->redirect.valid_infile = 1;
	token->redirect.r_in_type = NO_R_IN;
	token->redirect.r_out_type = NO_R_OUT;
	token->redirect.infile = NULL;
	token->redirect.outfile = NULL;
	token->redirect.heredoc_pipe = NULL;
	token->next = NULL;
}
