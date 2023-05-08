/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:10:35 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/05 09:55:58 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	ft_check_syntax(char *input)
{
	(void)input;
	return (0);
}

void ft_execute_cmd(char *input, char ***envp)
{
	if (!ft_memcmp(input, "env", 3))
	{
		ft_get_all_env(*envp);
	}
	else if (!ft_memcmp(input, "export\0", 7))
	{
		/* ft_printf("USER : %s\n", ft_getenv("USER", *envp));
		ft_printf("LOGNAME : %s\n", ft_getenv("LOGNAME", *envp));
		ft_setenv("USER", "SENJI", envp);
		ft_printf("USER : %s\n", ft_getenv("USER", *envp));
		ft_setenv("USER", "SENJIES", envp);
		ft_setenv("LOGNAME", "SENJIES", envp);
		ft_printf("USER : %s\n", ft_getenv("USER", *envp));
		ft_printf("LOGNAME : %s\n", ft_getenv("LOGNAME", *envp));
		ft_setenv("TEST1", "1", envp);
		ft_setenv("TEST2", "2", envp);
		ft_setenv("TEST3", "3", envp);
		ft_printf("TEST1 : %s\n", ft_getenv("TEST1", *envp));
		ft_printf("TEST2 : %s\n", ft_getenv("TEST2", *envp));
		ft_printf("TEST3 : %s\n", ft_getenv("TEST3", *envp));
		ft_setenv("TEST1", "11", envp);
		ft_setenv("TEST2", "22", envp);
		ft_setenv("TEST3", "33", envp);
		ft_printf("TEST1 : %s\n", ft_getenv("TEST1", *envp));
		ft_printf("TEST2 : %s\n", ft_getenv("TEST2", *envp));
		ft_printf("TEST3 : %s\n", ft_getenv("TEST3", *envp));
		ft_get_all_env(*envp);
		ft_unsetenv("TEST1", envp);
		ft_unsetenv("TEST2", envp);
		ft_unsetenv("TEST3", envp);
		ft_unsetenv("TEST1", envp);
		ft_unsetenv("TEST2", envp);
		ft_unsetenv("TEST3", envp); */
		ft_get_all_env(*envp);
		/* while (1); */
	}
	else if (!ft_memcmp(input, "export ", 7))
	{
		int	i;
		i = -1;
		while ((input + 6)[++i])
		{
			if ((input + 6)[i] == '=')
				break;
		}
		char *name = strndup(input + 7, i - 1);
		char *value = input + 7 + i;
		/* printf("name = %s\n", name);
		printf("value = %s\n", value); */
		if (ft_setenv(name, value, envp))
			printf ("Error : invalid export input\n");
	}
	else if (!ft_memcmp(input, "unset ", 6))
	{
		ft_unsetenv(input + 6, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	char	**envp_copy;

	(void)argv;
	if (argc != 1)
	{
		ft_fatal_error("minishel don't take arguments", E_ERROR_ARG);
	}
	if (isatty(STDIN_FILENO))					// check if is interactive environment
	{
		envp_copy = ft_str_arrdup(envp);
		while (1)
		{
			input = readline("$ ");				// write "$ " and waits an input and read it
			if (!input)
				break;
			add_history(input);					// function for retrieving written commands
			if (!ft_check_syntax(input))
			{
				ft_execute_cmd(input, &envp_copy);	// execute the command
				free(input);
				rl_on_new_line();
			}
		}
	}
	return (0);
}
