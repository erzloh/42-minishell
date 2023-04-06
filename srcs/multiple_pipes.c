/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:12:40 by eric              #+#    #+#             */
/*   Updated: 2023/04/04 11:57:03 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Return the number of commands in a token list
int	get_cmd_nb(t_token *token)
{
	int	cmd_nb;

	cmd_nb = 0;
	while (token)
	{
		if (token->cmd == ECHO ||
			token->cmd == PWD ||
			token->cmd == WC ||
			token->cmd == LS)
			cmd_nb++;
		token = token->next;
	}
	return (cmd_nb);
}

// Take a token.arg string and split the flags and the argument to a
// string array. Return NULL no flags was detected.
char	**split_arg(char *arg)
{
	char	**args;
	int		arg_nb;
	int		i;
	int		j;

	i = 0;
	j = 1;
	arg_nb = 1;
	while (arg[i])
	{
		if (arg[i] == '-')
		{
			while (arg[i + j] != ' ' ||
				arg[i + j] != '\t' ||
				arg[i + j] != '\n' ||
				arg[i + j] != '\v' ||
				arg[i + j] != '\f' ||
				arg[i + j] != '\r' ||
				arg[i + j] != 0)
			{

			}
		}
	}
}


// NOT FINISHED
// Get the i-th command and return it in a string array format
char	**get_cmd_str_arr(t_token *token, int i)
{
	char	**cmd_str_arr;
	char	**split_args;

	// I need to iterate to the i-th cmd

	if (token->arg != NULL)
		split_args = split_arg(token->arg);
	cmd_str_arr = malloc()
}

// Take a token as argument and returns an array of string arrays.
char ***token_to_arr(t_token *token)
{
	char	***cmd_arr; // array of string arrays
	int		cmd_nb;
	int		i;

	cmd_nb = get_cmd_nb(token);
	cmd_arr = malloc(sizeof(char**) * cmd_nb + 1);
	if (!cmd_arr)
		return (print_error("malloc", 1));
	i = 0;
	while (i < cmd_nb)
	{
		cmd_arr[i] = get_cmd_str_arr(token, i);
	}
}

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

int	multiple_pipe(char ***cmd_arr_arr)
{
	int	i;
	int	j;
	int	pipe_nb = 0;
	int	pipe_fd[pipe_nb][2];
	int	pid;
	int	children_nb;

	children_nb = pipe_nb + 1;
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
				if (close(pipe_fd[j][0]) < 0)
					return (print_error("close a read-end pipe", 1));
				if (close(pipe_fd[j][1]) < 0)
					return (print_error("close a write-end pipe", 1));
				j++;
			}
			// Execute the command
			if (execve(cmd_arr_arr[i][0], cmd_arr_arr[i], NULL) < 0)
				return (print_error("execve()", 1));
			// Should never reach here because execve() overwrite the process
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

int	main()
{
	char *cmd1_arr[] = {"/bin/echo", "-z", NULL};
	// char *cmd2_arr[] = {"/bin/pwd", "-a", NULL};
	// char *cmd2_arr[] = {"/usr/bin/grep", "pipe", NULL};
	// char *cmd3_arr[] = {"/usr/bin/wc", NULL};
	// char **cmd_arr_arr[] = { cmd1_arr, cmd2_arr, cmd3_arr };
	char **cmd_arr_arr[] = { cmd1_arr };
	// char **cmd2_arr_arr[] = { cmd2_arr };

	t_token token1;
	t_token token2;

	token1.cmd = LS;
	token1.arg = "-l";
	token1.next = &token2;
	token2.cmd = WC;
	token2.arg = NULL;
	token2.next = NULL;

	multiple_pipe(cmd_arr_arr);
	// multiple_pipe(cmd2_arr_arr);
}
