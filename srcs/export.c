/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:27:12 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/17 15:02:45 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_utils.h"

extern int g_status;

/* void	export(t_token *token, t_data *data)
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
} */

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
	i = 0;
	while (token->cmd_arr[1][i] && token->cmd_arr[1][i] != '=')
		i++;
	name = ft_strndup(token->cmd_arr[1], i);
	if (!name)
		fatal_error("Error with malloc() when calling ft_strndup()");
	if (!ft_is_valid_env_name(name))
	{
		printf("minishell: export: `%s': not a valid identifier\n", token->cmd_arr[1]);
		g_status = 1;
		return ;
	}
	if (token->cmd_arr[1][i] != '=')
		return ;
	value = token->cmd_arr[1] + i + 1;
	if (ft_setenv(name, value, &data->envp_cpy))
		g_status = 1;
	free(name);
	g_status = 0;
	if (!token->pid)
		exit(0);
}
