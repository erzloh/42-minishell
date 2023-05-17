/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:43:34 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/17 10:21:52 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	env(t_data *data)
{
	int	i;

	i = -1;
	while (data->envp_cpy[++i])
		printf("%s\n", data->envp_cpy[i]);
	exit(0);
}
