/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:15:16 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/19 15:20:01 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// OLD
// Set the terminal attributes so that unwanted ^C are not printed
// void	set_termios(void)
// {
// 	struct termios	saved;
// 	struct termios	attributes;

// 	tcgetattr(STDIN_FILENO, &saved);
// 	tcgetattr(STDIN_FILENO, &attributes);
// 	attributes.c_lflag &= ~ECHOCTL;
// 	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);
// }

// Set the terminal attributes so that unwanted ^C are not printed
void	set_termios(void)
{
	struct termios	termios;

	if ((tcgetattr(STDIN_FILENO, &termios)) == -1)
		fatal_error("Error with tcgetattr");
	termios.c_lflag &= ~(ECHOCTL);
	if ((tcsetattr(STDIN_FILENO, TCSANOW, &termios)) == -1)
		fatal_error("Error with tcgetattr");
}