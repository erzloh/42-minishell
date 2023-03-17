/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:12:10 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/17 18:38:08 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// CETTE FONCTION A POUR L'INSTANT COMME BUT DE TESTER LES FONCTIONS
void	ft_execute_cmd(char *input)
{
	int	i;

	if (!ft_memcmp(input, "exit", 4))
	{
		free(input);
		exit(0);
	}
	else if (!ft_memcmp(input, "env", 3))
	{
		ft_get_all_env();
	}
	else if (!ft_memcmp(input, "export ", 7))
	{
		ft_setenv("TEST", "BRUH");
		ft_setenv("TEST", "BRUHH");
		ft_setenv("TEST", "BRUHH");
		ft_setenv("TEST", "BRUHH");
		ft_setenv("TEST1", "BRUH");
		ft_setenv("TEST2", "BRUH");
		while (1);
	}
	else if (!ft_memcmp(input, "unset", 5))
	{
		
	}
	else
	{
		i = -1;
		while (input[++i])
		{
			if (ft_is_dollar(input[i]))
				ft_printf("%s\n", ft_getenv(ft_findenv(input)));
		}
	}
}