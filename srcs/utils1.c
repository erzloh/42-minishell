/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:19:05 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/22 16:41:30 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Print a default error message and append the first argument to it.
// Print the errno error message as well.
// Return the second argument.
int	print_error(char *err_msg, int ret_val)
{
	char	*err_msg_default;
	char	*err_msg_full;

	err_msg_default = "An error occurred when trying to ";
	err_msg_full = ft_strjoin(err_msg_default, err_msg);
	perror(err_msg_full);
	free(err_msg_full);
	return (ret_val);
}

void	fatal_error(char *err_msg)
{
	perror(err_msg);
	exit(-1);
}

int	is_builtin(t_token *token)
{
	if (ft_strncmp(token->cmd_arr[0], "echo", 5) == 0
		|| ft_strncmp(token->cmd_arr[0], "cd", 3) == 0
		|| ft_strncmp(token->cmd_arr[0], "pwd", 4) == 0
		|| ft_strncmp(token->cmd_arr[0], "export", 7) == 0
		|| ft_strncmp(token->cmd_arr[0], "unset", 6) == 0
		|| ft_strncmp(token->cmd_arr[0], "env", 4) == 0
		|| ft_strncmp(token->cmd_arr[0], "exit", 5) == 0)
		return (1);
	else
		return (0);
}

int	is_str_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

void	check_args(int ac)
{
	if (ac > 1)
	{
		printf("Error: minishell doesn't take any arguments\n");
		exit(E_ERROR_ARG);
	}
}
