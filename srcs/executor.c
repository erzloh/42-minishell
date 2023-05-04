/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:49:54 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/04 11:41:31 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	executor(t_token *token, t_data *data)
{
	create_pipes(data);
	set_pipe_fd_in_token(token, data);
	set_redirect_fd_in_token(token);
	create_children(token, data);
	close_pipes(data);
	// close redirection files
	wait_children(token);
	free_pipe_fd(data);
	return (0);
}
