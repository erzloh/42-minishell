/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:01:27 by eholzer           #+#    #+#             */
/*   Updated: 2023/04/21 11:19:58 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Returns an array of string arrays that represent each command
// and their arguments.
char	***get_cmds_arr(t_token *token)
{
	char	***cmds_arr;

	cmds_arr = malloc(sizeof(char **) * (token->cmds_nb + 1));
	if (!cmds_arr)
		return (NULL);
	if (fill_cmds_arr(cmds_arr, token) == -1)
	{
		free(cmds_arr);
		return (NULL);
	}
	cmds_arr[token->cmds_nb] = NULL;
	return (cmds_arr);
}

// Fill the commands array (cmds_arr) with string arrays 
int	fill_cmds_arr(char ***cmds_arr, t_token *token)
{
	int	i;

	i = 0;
	while (i < token->cmds_nb)
	{
		cmds_arr[i] = get_cmd_arr(token, i);
		if (!cmds_arr[i])
			return (-1);
		i++;
	}
	return (0);
}

// Returns a string array of the i-th command in the given token list
char	**get_cmd_arr(t_token *token, int i)
{
	int		n;
	char	**cmd_arr;
	int		cmd_arr_size;

	n = 0;
	while (token)
	{
		if (is_cmd(token->cmd))
		{
			if (n == i)
			{
				cmd_arr_size = get_cmd_arr_size(token);
				cmd_arr = malloc(sizeof(char *) * cmd_arr_size);
				if (!cmd_arr)
					return (NULL);
				fill_cmd_arr(&cmd_arr, token);
				return (cmd_arr);
			}
			n++;
		}
		token = token->next;
	}
	return (NULL);
}

// Fills the given command array.
// Should I protect all the strdup?...
void	fill_cmd_arr(char ***cmd_arr, t_token *token)
{
	(*cmd_arr)[0] = get_cmd_path(token->cmd);
	if (token->arg[0] && token->flag[0] == '\0')
	{
		(*cmd_arr)[1] = ft_strdup(token->arg);
		(*cmd_arr)[2] = NULL;
	}
	else if (token->arg[0] == '\0' && token->flag[0])
	{
		(*cmd_arr)[1] = ft_strdup(token->flag);
		(*cmd_arr)[2] = NULL;
	}
	else if (token->arg[0] && token->flag[0])
	{
		(*cmd_arr)[1] = ft_strdup(token->flag);
		(*cmd_arr)[2] = ft_strdup(token->arg);
		(*cmd_arr)[3] = NULL;
	}
	else
		(*cmd_arr)[1] = NULL;
}

// Returns the size of a command array.
int	get_cmd_arr_size(t_token *token)
{
	int	cmd_arr_size;

	cmd_arr_size = 2;
	if (token->arg[0])
		cmd_arr_size++;
	if (token->flag[0])
		cmd_arr_size++;
	return (cmd_arr_size);
}
