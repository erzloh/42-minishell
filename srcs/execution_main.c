/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:12:40 by eric              #+#    #+#             */
/*   Updated: 2023/04/21 14:38:11 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//  ----- Error handling function ------
// Make CD function, and also make a check if cmd == "cd", there should be no pipes
// Make sure that arg and flag are not NULL
// Make sure that token is not null

int	main()
{
	// char *cmd1_arr[] = {"/bin/pwd", NULL};
	// char *cmd2_arr[] = {"/usr/bin/grep", "pipe", NULL};
	// char *cmd3_arr[] = {"/usr/bin/wc", "-l", NULL};
	// char **cmd_arr_arr[] = { cmd1_arr, cmd2_arr, cmd3_arr };

	// Create token manually for testing purposes
	t_token	token1;
	t_token	token2;
	t_token	token3;
 
	token1.cmd = "ls";
	token1.arg = "-l";
	token1.flag = "";
	token1.next = &token2;

	token2.cmd = "|";
	token2.arg = "";
	token2.flag = "";
	token2.next = &token3;

	token3.cmd = "wc";
	token3.arg = "";
	token3.flag = "";
	token3.next = NULL;

	executor(&token1);
}