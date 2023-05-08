/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:15:59 by eric              #+#    #+#             */
/*   Updated: 2023/05/08 15:20:09 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
}
