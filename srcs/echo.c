/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:21:05 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/05 09:48:24 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(t_token *token)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (ft_strncmp(token->cmd_arr[1], "-n", 3) == 0)
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
