/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:15:59 by eric              #+#    #+#             */
/*   Updated: 2023/05/22 15:16:17 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(t_token *token)
{
	if (!token->cmd_arr[1])
	{
		printf("minishell: cd: an arguement is required\n");
		g_status = 1;
		return ;
	}
	if (chdir(token->cmd_arr[1]) != 0)
	{
		ft_printf("minishell: cd: %s: ", token->cmd_arr[1]);
		perror("");
		g_status = 1;
	}
	else
		g_status = 0;
	if (!token->pid)
		exit(0);
}
