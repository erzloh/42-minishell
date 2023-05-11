/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:27:12 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/11 15:07:28 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int g_status;

void	export(t_token *token, t_data *data)
{
	int		i;
	char	*name;
	char	*value;

	if (!token->cmd_arr[1])
	{
		ft_get_all_env(data->envp_cpy);
		exit (0);
	}
	i = -1;
	while (token->cmd_arr[1][++i])
		if (token->cmd_arr[1][i] == '=')
			break ;
	if (token->cmd_arr[1][i] != '=')
		return ;
	name = ft_strndup(token->cmd_arr[1], i);
	if (!name)
		fatal_error("Error with malloc() when calling ft_strndup()");
	value = token->cmd_arr[1] + i + 1;
	if (ft_setenv(name, value, &data->envp_cpy))
	{
		printf("minishell: export: invalid input\n");
		g_status = 1;
	}
	free(name);
	g_status = 0;
	if (!token->pid)
		exit(0);
}
