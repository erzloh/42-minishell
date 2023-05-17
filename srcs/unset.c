/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:28:41 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/17 15:04:27 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_utils.h"

extern int g_status;

/* void	unset(t_token *token, t_data *data)
{
	ft_unsetenv(token->cmd_arr[1], &data->envp_cpy);
	g_status = 0;
	if (!token->pid)
		exit(0);
} */

void	unset(t_token *token, t_data *data)
{
	if (token->cmd_arr[1])
	{
		if (!ft_is_valid_env_name(token->cmd_arr[1]))
		{
			printf("minishell: unset: `%s': not a valid identifier\n", token->cmd_arr[1]);
			g_status = 1; // pourquoi des fois tu mets exit et des fois tu mets g_status
			return ;
		}
		ft_unsetenv(token->cmd_arr[1], &data->envp_cpy);
	}
	g_status = 0;
	if (!token->pid)
		exit(0);
}
