/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:50:57 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/17 10:21:52 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

extern int g_status;

// Simulates the exit commands
void	exit_builtin(t_token *token)
{
	if (!token->cmd_arr[1])
	{
		printf("exit\n");
		exit(0);
	}
	else if (is_str_digit(token->cmd_arr[1]) && !token->cmd_arr[2])
	{
		printf("exit\n");
		exit(ft_atoi(token->cmd_arr[1]) % 256);
	}
	else if (is_str_digit(token->cmd_arr[1]) && token->cmd_arr[2])
	{
		printf("exit\n");
		printf("minishell: exit: too many arguments\n");
		g_status = 1;
	}
	else if (!is_str_digit(token->cmd_arr[1]))
	{
		printf("exit\n");
		printf("minishell: exit: %s: numeric argument required\n", token->cmd_arr[1]);
		exit(255);
	}
	if (!token->pid)
		exit(1);
}
