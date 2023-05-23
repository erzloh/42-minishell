/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:51:07 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/23 15:40:45 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "check_input_syntax.h"

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
		if (data.input[0])
			add_history(data.input);
		if (ft_is_correct_syntax(data.input))
		{
			init_signal(exec_handler);
			process_input(&data);
		}
		ft_free_data(&data);
	}
	ft_free_2d_char(data.envp_cpy);
	ft_free_data(&data);
	return (0);
}

// Initialize the data structure
void	init_data(t_data *data, char **envp)
{
	data->envp_cpy = ft_str_arrdup(envp);
	set_termios();
	g_status = 0;
	data->input = NULL;
	data->formatted_input = NULL;
	data->tokens_nb = 0;
	data->token = NULL;
	data->pipe_fd = NULL;
}
