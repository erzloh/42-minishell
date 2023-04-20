/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_42.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:12:40 by eric              #+#    #+#             */
/*   Updated: 2023/04/20 17:16:38 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ---- TO DO -----
// Make free_cmds_arr function
// Make free pipe_fd function

//  ----- Error handling function ------
// Make CD function, and also make a check if cmd == "cd", there should be no pipes
// Make sure that arg and flag are not NULL
// Check if 



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

// Compare two strings. Return 0 if they're the same.
// Return -1 if one or both of the args are NULL.
int	is_equal(const char *s1, const char *s2)
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

// Get the path of the given command
char	*get_cmd_path(char *cmd)
{
	if (is_equal(cmd, "pwd") == 1)
		return (ft_strdup("/bin/pwd"));
	else if (is_equal(cmd, "echo") == 1)
		return (ft_strdup("/bin/echo"));
	else if (is_equal(cmd, "ls") == 1)
		return (ft_strdup("/bin/ls"));
	else if (is_equal(cmd, "wc") == 1)
		return (ft_strdup("/usr/bin/wc"));
	else
		return (NULL);
}

// Returns the size of a command array.
int	get_cmd_arr_size(t_token *token)
{
	int	cmd_arr_size;

	cmd_arr_size = 2;
	if (token->arg[0])
		cmd_arr_size++;
	if (token->flag[0])
		cmd_arr_size++;
	return (cmd_arr_size);
}

// Fills the given command array.
// Should I protect all the strdup?...
void	fill_cmd_arr(char ***cmd_arr, t_token *token)
{
	(*cmd_arr)[0] = get_cmd_path(token->cmd);
	if (token->arg[0] && token->flag[0] == '\0')
	{
		(*cmd_arr)[1] = ft_strdup(token->arg);
		(*cmd_arr)[2] = NULL;
	}
	else if (token->arg[0] == '\0' && token->flag[0])
	{
		(*cmd_arr)[1] = ft_strdup(token->flag);
		(*cmd_arr)[2] = NULL;
	}
	else if (token->arg[0] && token->flag[0])
	{
		(*cmd_arr)[1] = ft_strdup(token->flag);
		(*cmd_arr)[2] = ft_strdup(token->arg);
		(*cmd_arr)[3] = NULL;
	}
	else
		(*cmd_arr)[1] = NULL;
}

// Returns a string array of the i-th command in the given token list
char	**get_cmd_arr(t_token *token, int i)
{
	int		n;
	char	**cmd_arr;
	int		cmd_arr_size;

	n = 0;
	while (token)
	{
		if (is_cmd(token->cmd))
		{
			if (n == i)
			{
				cmd_arr_size = get_cmd_arr_size(token);
				cmd_arr = malloc(sizeof(char *) * cmd_arr_size);
				if (!cmd_arr)
					return (NULL);
				fill_cmd_arr(&cmd_arr, token);
				return (cmd_arr);
			}
			n++;
		}
		token = token->next;
	}
	return (NULL);
}

// Fill the commands array (cmds_arr) with string arrays 
int	fill_cmds_arr(char ***cmds_arr, t_token *token)
{
	int	i;

	i = 0;
	while (i < token->cmds_nb)
	{
		cmds_arr[i] = get_cmd_arr(token, i);
		if (!cmds_arr[i])
			return (-1);
			// free memory
		i++;
	}
	return (0);
}


// Returns an array of string arrays that represent each command and their arguments
char	***get_cmds_arr(t_token *token)
{
	char	***cmds_arr;

	cmds_arr = malloc(sizeof(char **) * (token->cmds_nb + 1));
	if (!cmds_arr)
		return (NULL); // use print_error() instead
	// write directly the content of fill_cmds_arr()
	if (fill_cmds_arr(cmds_arr, token) == -1)
	{
		free(cmds_arr);
		return (NULL);
	}
	cmds_arr[token->cmds_nb] = NULL;
	return (cmds_arr);
}

int	get_pipes_nb(t_token *token)
{
	int	pipes_nb;

	pipes_nb = 0;
	while (token)
	{
		if (is_equal(token->cmd, "|") == 1)
			pipes_nb++;
		token = token->next;
	}
	return (pipes_nb);
}

// Create pipes
int	create_pipes(int ***pipe_fd, int pipes_nb)
{
	int	i;

	i = 0;
	*pipe_fd = malloc(sizeof(int *) * pipes_nb);
	if (!(*pipe_fd))
		return (print_error("to malloc a pipe fd", -1));
	while (i < pipes_nb)
	{
		(*pipe_fd)[i] = malloc(sizeof(int) * 2);
		if (!(*pipe_fd)[i])
			return (print_error("to malloc a pipe", -1));
		i++;
	}
	i = 0;
	while (i < pipes_nb)
	{
		if (pipe((*pipe_fd)[i]) < 0)
			return (print_error("to create a pipe", -1));
		i++;
	}
	return (0);
}

int	exec_child(int pipes_nb, int **pipe_fd, char ***cmds_arr, int i)
{
	int	children_nb;
	int	j;

	children_nb = pipes_nb + 1;
	// Redirect standard input
	if (i != 0)
		if (dup2(pipe_fd[i - 1][0], STDIN_FILENO) < 0)
			return (print_error("dup2() to redirect stdin", -1));
	// Redirect standard output
	if (i < children_nb - 1)
		if (dup2(pipe_fd[i][1], STDOUT_FILENO) < 0)
			return (print_error("dup2() to redirect stdout", -1));
	// Close all the pipes in the child
	j = 0;
	while (j < pipes_nb)
	{
		// Protect closes?
		close(pipe_fd[j][0]);
		close(pipe_fd[j][1]);
		j++;
	}
	// Execute the command
	execve(cmds_arr[i][0], cmds_arr[i], NULL);
	// Should never reach here
	return (print_error("execute a command", -1));
}

int	create_children(int pipes_nb, int **pipe_fd, char ***cmds_arr)
{
	int	pid;
	int	i;
	int	children_nb;

	children_nb = pipes_nb + 1;
	i = 0;
	while (i < children_nb)
	{
		pid = fork();
		if (pid < 0)
			return (print_error("fork", 1));
		// Child process
		if (pid == 0)
		{
			if (exec_child(pipes_nb, pipe_fd, cmds_arr, i) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

// Completes the missing complementary data of the token (and its next elements), 
// such as the cmds_nb or the pipes_nb.
void	complete_token(t_token *token)
{
	int		cmds_nb;
	int		pipes_nb;

	pipes_nb = get_pipes_nb(token);
	cmds_nb = get_cmds_nb(token);
	while (token)
	{
		token->cmds_nb = cmds_nb;
		token->pipes_nb = pipes_nb;
		token = token->next;
	}
}

// Executes the command line given by the token and its next elements.
// @param token A pointer to a token.
// @return Returns 0 if there are no errors, 1 if there is one.
int	executor(t_token *token)
{
	// int	j;
	// int	pid;
	int		i;
	int		children_nb;
	char	***cmds_arr;
	int		**pipe_fd;

	if (!token) // is this check necessary? is token already not null for sure?
		return (1);
	complete_token(token);
	children_nb = token->pipes_nb + 1;
	if (create_pipes(&pipe_fd, token->pipes_nb) == -1)
		return (1);
	cmds_arr = get_cmds_arr(token);
	if (!cmds_arr)
		return (print_error("to malloc cmds_arr", 1));
	// Create the children processes
	if (create_children(token->pipes_nb, pipe_fd, cmds_arr) == -1)
		return (1);
	// Close all the pipes in the parent
	i = 0;
	while (i < token->pipes_nb)
	{
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
		i++;
	}
	// Wait for all the children to terminate
	i = -1;
	while (++i < token->pipes_nb)
		wait(NULL);
	return (0);
}

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

	token1.cmd = "echo";
	token1.arg = "bonjour";
	token1.flag = "-a";
	token1.next = NULL;

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
