/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:12:10 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/16 17:16:42 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_cmd(char *input)
{
	if (!ft_memcmp(input, "exit", 4))
	{
		free(input);
		exit(0);
	}
}