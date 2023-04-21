/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:28:29 by eholzer           #+#    #+#             */
/*   Updated: 2023/04/21 11:37:09 by eholzer          ###   ########.fr       */
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

// Compare two strings. Return 0 if they're the same.
// Return -1 if one or both of the args are NULL.
int	is_equal(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}

// Completes the missing complementary data of the token
// (and its next elements), such as the cmds_nb or the pipes_nb.
void	complete_token(t_token *token)
{
	int		cmds_nb;
	int		pipes_nb;

	pipes_nb = get_pipes_nb(token);
	cmds_nb = get_cmds_nb(token);
	while (token)
	{
		token->cmds_nb = cmds_nb;
		token->pipes_nb = pipes_nb;
		token = token->next;
	}
}
