/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:23:02 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/16 11:02:53 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include "minishell.h"

void	sigINGORE_handler(int signum)
{
	(void)signum;
}

void	sigINT_handler(int signum)
{
	if (signum == SIGINT)
		write(1, "\n", 1); // utiliser des fonctions asynchrone-safe
}

int	init_signal(int signum, void(*handler)(int))
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
