/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:00:05 by eholzer           #+#    #+#             */
/*   Updated: 2023/04/21 15:31:34 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(t_token *token)
{
	if (chdir(token->arg) != 0)
		print_error("to cd", -1); // error must be treated like in the real bash
	return (0);
}

int main()
{
	t_token	token1;
	t_token	token2;

	token1.cmd = "cd";
	token1.arg = "/Users/eholzer/Desktopa";

	token2.cmd = "pwd";
	token2.arg = "";
	token2.flag = "";
	token2.next = NULL;
	cd(&token1);
	executor(&token2);
}
