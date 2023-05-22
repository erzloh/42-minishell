/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:51:07 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/22 14:26:32 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "check_input_syntax.h"

int	g_status;

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	(void) av;
	check_args(ac);
	init_data(&data, envp);
	while (1)
	{
		init_signal(prompt_handler);
		data.input = readline("minishell$ ");
		if (!data.input)
			break ;
		init_signal(exec_handler);
		if (!ft_is_empty_cmd(data.input))
		{
			add_history(data.input);
			if (ft_is_correct_syntax(data.input))
			{
				// data.formatted_input = ft_format_input(input);
				// if (ft_is_correct_syntax(data.formatted_input))
				// data.token = create_token(data.formatted_input);
				// execute_cmd(data.token);
				process_input(&data);
			}
		}
		free(data.input); // We can do free_all() here as well I guess, to free the input, the token, etc...
	}
	return (0);
}

// Initialize the data structure
void	init_data(t_data *data, char **envp)
{
	data->envp_cpy = ft_str_arrdup(envp);
	set_termios();
	g_status = 0;
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
		char *name = ft_strndup(input + 7, i - 1);
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
	else
	{
		int		i;
		/* int		len;
		char	**split = ft_lexer(input);
		
		len = 0;
		if (!split)
			return ;
		while (split[len])
			len++;
		printf("lexer = {");
		i = -1;
		while (++i < len)
		{
			printf("%s", split[i]);
			if (i < len - 1)
				printf(", ");
		}
		printf("}\n");
		split = ft_expander(split, *envp);
		if (!split)
			return ;
		while (split[len])
			len++;
		printf("expender = {");
		i = -1;
		while (++i < len)
		{
			printf("%s", split[i]);
			if (i < len - 1)
				printf(", ");
		}
		printf("}\n");
		ft_free_2d_char(split); */
		t_data *data;

		data = malloc(sizeof(t_data));
		if (!data)
			ft_fatal_error("memory allocation error\n", E_ERROR_MALLOC);
		data->input = input;
		data->formatted_input = ft_lexer(data->input);
		data->formatted_input = ft_expander(data->formatted_input, *envp);
		printf("formatted_input = {");
		i = -1;
		while (data->formatted_input[++i])
			printf("%s, ", data->formatted_input[i]);
		printf("}\n");
		data->tokens_nb = ft_create_token(&data->token, data->formatted_input);
		/* printf("here\n"); */
		ft_display_token(data->token);
	}
}

// int	main()
// {
// 	// t_token	token;
// 	char	**envp_cpy;
// 	char	*cmd_arr[] = {"/usr/bin/env", NULL};

// 	// token.cmd_arr = cmd_arr;
// 	// token.is_valid_cmd = 0;
// 	envp_cpy = NULL;
// 	// set_cmd_path(&token, envp_cpy);
// 	// printf("cmd = %s\n", token.cmd_arr[0]);
// 	// printf("is_valid_cmd = %i\n", token.is_valid_cmd);
// 	execve(cmd_arr[0], cmd_arr, envp_cpy);
// 	perror("Error");
// }
