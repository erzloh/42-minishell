/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:12:10 by alesspal          #+#    #+#             */
/*   Updated: 2023/04/21 16:38:24 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"
#include "../incl/tokenizer.h"

// CETTE FONCTION A POUR L'INSTANT COMME BUT DE TESTER LES FONCTIONS
void	ft_execute_cmd(char *input)
{
	if (!ft_memcmp(input, "exit", 4))
	{
		free(input);
		exit(0);
	}
	else if (!ft_memcmp(input, "env", 3))
	{
		ft_get_all_env();
	}
	else if (!ft_memcmp(input, "export", 7))
	{
		ft_printf("USER : %s\n", ft_getenv("USER"));
		ft_printf("LOGNAME : %s\n", ft_getenv("LOGNAME"));
		ft_setenv("USER", "SENJI");
		ft_printf("USER : %s\n", ft_getenv("USER"));
		ft_setenv("USER", "SENJIES");
		ft_setenv("LOGNAME", "SENJIES");
		ft_printf("USER : %s\n", ft_getenv("USER"));
		ft_printf("LOGNAME : %s\n", ft_getenv("LOGNAME"));
		ft_setenv("TEST1", "1");
		ft_setenv("TEST2", "2");
		ft_setenv("TEST3", "3");
		ft_printf("TEST1 : %s\n", ft_getenv("TEST1"));
		ft_printf("TEST2 : %s\n", ft_getenv("TEST2"));
		ft_printf("TEST3 : %s\n", ft_getenv("TEST3"));
		ft_setenv("TEST1", "11");
		ft_setenv("TEST2", "22");
		ft_setenv("TEST3", "33");
		ft_printf("TEST1 : %s\n", ft_getenv("TEST1"));
		ft_printf("TEST2 : %s\n", ft_getenv("TEST2"));
		ft_printf("TEST3 : %s\n", ft_getenv("TEST3"));
		ft_get_all_env();
		ft_unsetenv("TEST1");
		ft_unsetenv("TEST2");
		ft_unsetenv("TEST3");
		ft_unsetenv("TEST1");
		ft_unsetenv("TEST2");
		ft_unsetenv("TEST3");
		ft_get_all_env();
		/* while (1); */
	}
	else if (!ft_memcmp(input, "unset ", 6))
	{
		ft_unsetenv(input + 6);
		ft_get_all_env();
	}
	else
	{
		t_token *token;

		token = ft_laxing_cmd(input);
		// ft_display_token(token);
		token = ft_expend_cmd(token);
		// ft_printf("---final token---\n");
		// ft_display_token(token);
		// ft_printf("-----------------\n");
		executor(token);
		ft_free_token(token);
		/* while (1); */
	}
}
