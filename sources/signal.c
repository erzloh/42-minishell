/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:23:02 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/13 17:09:01 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int signum)
{
	if (signum == SIGINT)
		printf("\n");
}

int	init_signal(int signum, void(*handler)(int))
{
	struct sigaction sa;

	sa.__sigaction_u.__sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(signum, &sa, NULL) == -1)
	{
		perror("sigaction");
		return (-1);
	}
	return (0);
}