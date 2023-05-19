/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:21:05 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/19 13:54:34 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	echo(t_token *token)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (token->cmd_arr[1] && ft_strncmp(token->cmd_arr[1], "-n", 3) == 0)
	{
		i++;
		flag = 1;
	}
	while (token->cmd_arr[i])
	{
		printf("%s", token->cmd_arr[i]);
		if (token->cmd_arr[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (!flag)
		printf("\n");
	exit(0);
}
