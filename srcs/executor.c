/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:49:54 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/02 16:29:47 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	executor(t_token *token, t_data *data)
{
	create_pipes(data);
	set_pipe_fd_in_token(token, data);
	create_children(token, data);
	close_pipes(data);
	wait_children(token);
	return (0);
}
