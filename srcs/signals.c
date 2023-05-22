/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:36:17 by eric              #+#    #+#             */
/*   Updated: 2023/05/22 12:14:54 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int g_status;

// Old signal code
// void	init_signal(void)
// {
// 	struct sigaction	sigint_sa;

// 	sigint_sa.sa_handler = &sigint_handler;
// 	sigaction(SIGINT, &sigint_sa, NULL);
// }

// void	sigint_handler(int sig)
// {
// 	(void) sig;
// 	rl_replace_line("", 0);
// 	rl_on_new_line();
// 	write(1, "\n", 1);
// 	rl_redisplay();
// 	g_status = 1; // I should check if there is a blocking command being executed -> g_status = 130
// }

void	init_signal(void (*signal_handler)(int))
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

void	prompt_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_status = 1;
	}
}

void	exec_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "^C\n", 3);
		rl_replace_line("", 0);
		rl_on_new_line();
		g_status = 130;
	}
	if (sig == SIGQUIT)
	{
		write(1, "^\\Quit: 3\n", 10);
		rl_replace_line("", 0);
		rl_on_new_line();
		g_status = 131;
	}
}
