/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:28:41 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/11 15:07:28 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int g_status;

void	unset(t_token *token, t_data *data)
{
	ft_unsetenv(token->cmd_arr[1], &data->envp_cpy);
	g_status = 0;
	if (!token->pid)
		exit(0);
}
