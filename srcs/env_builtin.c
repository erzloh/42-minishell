/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:43:34 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/23 16:06:45 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_utils.h"

void	env(t_data *data)
{
	int	i;

	i = -1;
	if (ft_find_index_env("PATH", data->envp_cpy) == -1)
	{
		printf("minishell: env: command not found\n");
		exit(127);
	}
	while (data->envp_cpy[++i])
		printf("%s\n", data->envp_cpy[i]);
	exit(0);
}
