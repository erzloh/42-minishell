/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:42:16 by eholzer           #+#    #+#             */
/*   Updated: 2023/04/25 15:45:09 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "minishell.h"

// Sets the token->cmd_path to the path of cmd
// Returns 0 if it succeeds
// Returns MALLOC_ERR in case of a malloc error
// Returns CMD_NOT_FOUND if the command is not found
int	set_cmd_path(t_token *token)
{
	char	*path_str;
	char	**path_arr;
	int		i;
	char	*tmp_path;

	path_str = ft_getenv("PATH"); // Function not definitive. We must be careful to get a copy and not the original address in the env array
	if (!path_str)
	{
		token->is_cmd_valid = 0;
		return (CMD_NOT_FOUND);
	}
	path_arr = ft_split(path_str, ':');
	if (!path_arr)
		return (print_error("to malloc path_arr", MALLOC_ERR));
	i = -1;
	// Supposes that cmd is an absolute path and checks if the cmd path is passing through the paths from PATH
	while (path_arr[++i])
		if (ft_strncmp(path_arr[i], token->cmd, ft_strlen(path_arr[i])) == 0)
			// Path is valid
			if (access(token->cmd, F_OK) == 0)
			{
				token->cmd_path = token->cmd;
				// free(path_str); // only if get_env gives a copy
				ft_free_2d_tab((void **)path_arr);
				token->is_cmd_valid = 1;
				return (0);
			}
	// If not an absolute path, checks if the commands exists in one of the paths from PATH
	i = -1;
	while (path_arr[++i])
	{
		tmp_path = ft_strjoin3(path_arr[i], "/", token->cmd);
		if (!tmp_path)
			return (print_error("to malloc path_arr", MALLOC_ERR));
		if (access(tmp_path, F_OK) == 0)
		{
			token->cmd_path = tmp_path;
			// free(path_str); // only if get_env gives a copy
			ft_free_2d_tab((void **)path_arr);
			token->is_cmd_valid = 1;
			return (0);
		}
	}
	token->is_cmd_valid = 0;
	return (CMD_NOT_FOUND);
}

// // Returns the path of the given command.
// // If the commands doesn't exists, returns NULL.
// char *get_path(char *cmd)
// {
// 	// eventuellement checker si cmd est absolue ou relatif

// 	// try to check if the cmd is an absolute path
// 	// split the PATH
// 	// for each path, check if first path-len characters of the cmd are the same as the current path 
// 	// -> if yes the cmd is in PATH -> verify if the cmd actually exists with access()
// 	char **path;

// 	path = 
	

// 	// try to check if the cmd is just a command
// 	// iterate through each path and make a tmp_path = strjoin(path[i], cmd) and access*(tmp_path , F_OK)
// }
