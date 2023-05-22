/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:49:54 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/22 15:00:36 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	executor(t_token *token, t_data *data)
{
	set_cmd_path_in_all_token(data->token, data->envp_cpy);
	create_pipes(data);
	set_pipe_fd_in_token(token, data);
	set_redirect_fd_in_token(token);
	if (!is_cmd_childable(token))
		exec_builtin(token, data);
	else
		create_children(token, data);
	clean_up(token, data);
	wait_children(token);
}
