/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:28:41 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/22 16:42:24 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_utils.h"

void	unset(t_token *token, t_data *data)
{
	if (token->cmd_arr[1])
	{
		if (!ft_is_valid_env_name(token->cmd_arr[1]))
		{
			printf("minishell: unset: `%s': not a valid identifier\n",
				token->cmd_arr[1]);
			g_status = 1;
			return ;
		}
		ft_unsetenv(token->cmd_arr[1], &data->envp_cpy);
	}
	g_status = 0;
	if (!token->pid)
		exit(0);
}
