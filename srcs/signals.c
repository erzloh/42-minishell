/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:16:51 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/17 10:55:43 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

extern int g_status;

void	ft_sigINGORE_handler(int signum)
{
	(void)signum;
}

void	ft_sigINT_handler(int signum)
{
	if (signum == SIGINT)
		write(1, "\n", 1); // utiliser des fonctions asynchrone-safe
}

int	ft_init_signal(int signum, void(*handler)(int))
{
	struct sigaction sa;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(signum, &sa, NULL) == -1)
	{
		perror("sigaction");
		return (-1);
	}
	return (0);
}


