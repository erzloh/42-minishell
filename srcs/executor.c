/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:49:54 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/09 14:18:34 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	executor(t_token *token, t_data *data)
{
	create_pipes(data);
	set_pipe_fd_in_token(token, data);
	set_redirect_fd_in_token(token);
	if (!is_cmd_childable(token))
		exec_builtin(token, data);
	else
		create_children(token, data);
	clean_up(token, data);
	wait_children(token);
	return (0);
}
