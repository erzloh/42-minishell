/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_42.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:12:40 by eric              #+#    #+#             */
/*   Updated: 2023/04/06 12:48:51 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	create_pipes()
// int	create_children()

// Print a default error message and append the first argument to it.
// Print the errno error message as well.
// Return the second argument.
int	print_error(char *err_msg, int ret_val)
{
	char	*err_msg_default;
	char	*err_msg_full;

	err_msg_default = "An error occurred when trying to ";
	err_msg_full = ft_strjoin(err_msg_default, err_msg);
	perror(err_msg_full);
	free(err_msg_full);
	return (ret_val);
}

// Make free_cmds_arr function

// Make CD function, and also make a check if cmd == "cd", there should be no pipes

// Compare two strings. Return 0 if they're the same.
// Return -1 if one or both of the args are NULL.
int	is_equal(const char s1*, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}

// Return 1 if the string is a valid command.
int	is_cmd(char *str)
{
	if (is_equal(str, "echo") == 1
		|| is_equal(str, "pwd") == 1
		|| is_equal(str, "ls") == 1
		|| is_equal(str, "wc") == 1)
		return (1);
	else
		return (0);
}

// Return the number of commands in the given token list
int	get_cmds_nb(t_token *token)
{
	int	cmds_nb;

	cmds_nb = 0;
	while (token)
	{
		if (is_cmd(token->cmd))
			cmds_nb++;
		token = token->next;
	}
	return (cmds_nb);
}

// // NOT USED, NOT FINISHED
// // Update the value of i if there are whitespaces from str[i]
// void	skip_whitespaces(char *str, int *i)
// {
// 	if (!str)
// 		return ;
// 	while (str[*i] == ' ' || str[*i] == '\t')
// 	{
// 		(*i)++;
// 	}
// }

// // Counts the number of flags in a string argument
// int	get_flag_nb(char *arg)
// {
// 	int	i;
// 	int	flag_nb;

// 	i = 0;
// 	flag_nb = 0;
// 	if (!arg)
// 		return (-1);
// 	while (arg[i])
// 	{
// 		skip_whitespaces(arg, &i);
// 		if (arg[i] != '-')
// 			break ;
// 		else
// 		{
// 			flag_nb++;
// 			while ((arg[i] != ' ' && arg[i] != '\t') && arg[i])
// 				i++;
// 			if (!arg[i])
// 				break ;
// 		}
// 		i++;
// 	}
// 	return (flag_nb);
// }

// // Check if there are flags in the string and if so,
// // split each element into an string array
// char	**split_flags(char *arg)
// {
// 	char	**args;
// 	int		i;
// 	int		arg_nb;

// 	i = 0;
// 	arg_nb = get_flag_nb(arg);
// 	while (arg[i])
// 	{
// 		if (arg[i] == '-')
// 		{
// 			while ((arg[i + j] != ' ' || arg[i + j] != '\t') && arg[i + j])
// 				j++;
// 		}
// 		i++;
// 	}
// }



// char	**split_echo_n_flag(char *arg)
// {
	
// }

// Get the path of the given command
char *get_cmd_path(char *cmd)
{
	if (is_equal(cmd, "pwd") == 1)
		return (ft_strdup("/bin/pwd"));
}

// Return a string array of the i-th command in the given token list
char	**get_cmd_arr(t_token token, int i)
{
	int		n;
	char	**cmd_arr;
	int		cmd_arr_size;

	n = 0;
	cmd_arr_size = 2;
	while (token)
	{
		if (is_cmd(token->cmd))
			if (i == n)
			{
				// Make sure to check if the arg is null -> if so: not execute splitflag()
				// fill cmd_arr
				if (is_equal(token->cmd, "echo") == 1)
				{

				}
				if (token->arg[0])
					cmd_arr_size++;
				cmd_arr = malloc(sizeof(char *) * cmd_arr_size);
				if (!cmd_arr)
					return (NULL);
				cmd_arr[0] = get_cmd_path(token->cmd);
				if (token->arg[0])
				{
					cmd_arr[1] = ft_strdup(token->arg);
					cmd_arr[2] = NULL;
				}
				else
					cmd_arr[1] = NULL;
				return (cmd_arr);
			}
		token = token->next;
	}
}

// Fill the commands array (cmds_arr) with string arrays 
int	fill_cmds_arr(char ***cmds_arr, t_token *token)
{
	int	cmds_nb;
	int	i;

	cmds_nb = get_cmds_nb;
	i = 0;
	while (i < cmds_nb)
	{
		cmds_arr[i] = get_cmd_arr(token, i);
		if (!cmds_arr[i])
			return (0)
		// check for malloc errors
		i++;
	}
}


// Return an array of string arrays that represent each command and their arguments
char	***get_cmds_arr(t_token *token)
{
	char	***cmds_arr;
	int		cmds_nb;

	cmds_nb = get_cmds_nb(token);
	cmds_arr = malloc(sizeof(char **) * (cmds_nb + 1));
	if (!cmds_arr)
		return (NULL);
	if (!fill_cmds_arr(cmds_arr, token))
		return (NULL);
	// check errors
	return (cmds_arr);
}

int	multiple_pipe(char ***cmd_arr_arr)
{
	int	i;
	int	j;
	int	pipe_nb = 2;
	int	pipe_fd[pipe_nb][2];
	int	pid;
	int	children_nb;
	char	***cmd_arr;

	children_nb = pipe_nb + 1;

	// MAKE SURE THAT TOKEN IS NOT NULL

	cmds_arr = get_cmds_arr(token);
	if (!cmds_arr)
		return (print_error("to malloc"));
	
	// Create the pipes
	i = 0;
	while (i < pipe_nb)
	{
		if (pipe(pipe_fd[i]) < 0)
			return (print_error("to create a pipe", 1));
		i++;
	}
	// Create the children processes
	i = 0;
	while (i < children_nb)
	{
		pid = fork();
		if (pid < 0)
			return (print_error("fork", 1));
		// Child process
		if (pid == 0)
		{
			// Redirect standard input
			if (i != 0)
				if (dup2(pipe_fd[i - 1][0], STDIN_FILENO) < 0)
					return (print_error("dup2() to redirect stdin", 1));
			// Redirect standard output
			if (i < children_nb - 1)
				if (dup2(pipe_fd[i][1], STDOUT_FILENO) < 0)
					return (print_error("dup2() to redirect stdout", 1));
			// Close all the pipes in the child
			j = 0;
			while (j < pipe_nb)
			{
				close(pipe_fd[j][0]);
				close(pipe_fd[j][1]);
				j++;
			}
			// Execute the command
			execve(cmd_arr_arr[i][0], cmd_arr_arr[i], NULL);
			// Should never reach here
			return (print_error("execute a command", 1));
		}
		i++;
	}
	// Close all the pipes in the parent
	i = 0;
	while (i < pipe_nb)
	{
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
		i++;
	}
	// Wait for all the children to terminate
	i = -1;
	while (++i < pipe_nb)
		wait(NULL);
	return (0);
}

int	main(int ac, char **av)
{
	char *cmd1_arr[] = {"/bin/pwd", NULL};
	char *cmd2_arr[] = {"/usr/bin/grep", "pipe", NULL};
	char *cmd3_arr[] = {"/usr/bin/wc", "-l", NULL};
	char **cmd_arr_arr[] = { cmd1_arr, cmd2_arr, cmd3_arr };

	// Create token manually for testing purposes

	multiple_pipe(cmd_arr_arr);
}
