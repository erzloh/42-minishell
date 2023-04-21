/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:20:28 by eholzer           #+#    #+#             */
/*   Updated: 2023/04/21 11:20:50 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Return 1 if the string is a valid command.
int	is_cmd(char *str)
{
	if (is_equal(str, "echo") == 1
		|| is_equal(str, "pwd") == 1
		|| is_equal(str, "ls") == 1
		|| is_equal(str, "wc") == 1)
		return (1);
	else
		return (0);
}

// Return the number of commands in the given token list
int	get_cmds_nb(t_token *token)
{
	int	cmds_nb;

	cmds_nb = 0;
	while (token)
	{
		if (is_cmd(token->cmd))
			cmds_nb++;
		token = token->next;
	}
	return (cmds_nb);
}

// Get the path of the given command
char	*get_cmd_path(char *cmd)
{
	if (is_equal(cmd, "pwd") == 1)
		return (ft_strdup("/bin/pwd"));
	else if (is_equal(cmd, "echo") == 1)
		return (ft_strdup("/bin/echo"));
	else if (is_equal(cmd, "ls") == 1)
		return (ft_strdup("/bin/ls"));
	else if (is_equal(cmd, "wc") == 1)
		return (ft_strdup("/usr/bin/wc"));
	else
		return (NULL);
}
