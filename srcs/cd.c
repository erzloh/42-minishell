/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:15:59 by eric              #+#    #+#             */
/*   Updated: 2023/05/17 10:21:52 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

extern int g_status;

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
