/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:56:30 by eholzer           #+#    #+#             */
/*   Updated: 2023/04/24 10:17:13 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	print_shell_error(char *err_msg, int ret_val)
// {
// 	ft_printf("%s", err_msg);
// 	return (ret_val);
// }

int	check_errors(t_token *token)
{
	// Check if token is NULL
	if (!token)
		return (-1);
	// Check if cmd or arg or flag is NULL => malloc error
	if (!token->cmd || !token->arg || !token->flag)
		return (MALLOC_ERR);
	// Check if commmand exists
	if (!is_cmd(token->cmd))
	{
		ft_printf("minishell: %s: command not found\n", token->cmd);
		return (-1);
	}
	return (0);
}
