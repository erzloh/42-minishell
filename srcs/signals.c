/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:36:17 by eric              #+#    #+#             */
/*   Updated: 2023/05/19 14:01:58 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int g_status;

void	init_signal(void)
{
	struct sigaction	sigint_sa;

	sigint_sa.sa_handler = &sigint_handler;
	sigaction(SIGINT, &sigint_sa, NULL);
}

void	sigint_handler(int sig)
{
	(void) sig;
	rl_replace_line("", 0);
	rl_on_new_line();
	write(1, "\n", 1);
	rl_redisplay();
	g_status = 1; // I should check if there is a blocking command being executed -> g_status = 130
}
