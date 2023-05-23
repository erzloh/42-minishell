/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:15:59 by eric              #+#    #+#             */
/*   Updated: 2023/05/23 15:39:51 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"

void	cd(t_token *token, t_data *data)
{
	char	cwd[1024];

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
	{
		ft_setenv("OLDPWD", ft_getenv("PWD", data->envp_cpy),
			&data->envp_cpy);
		getcwd(cwd, sizeof(cwd));
		ft_setenv("PWD", cwd, &data->envp_cpy);
		g_status = 0;
	}
	if (!token->pid)
		exit(0);
}
