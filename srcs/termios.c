/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:15:16 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/22 16:39:55 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Set the terminal attributes so that unwanted ^C are not printed
void	set_termios(void)
{
	struct termios	termios;

	if ((tcgetattr(STDIN_FILENO, &termios)) == -1)
		fatal_error("Error with tcgetattr");
	termios.c_lflag &= ~ECHOCTL;
	if ((tcsetattr(STDIN_FILENO, TCSANOW, &termios)) == -1)
		fatal_error("Error with tcgetattr");
}
