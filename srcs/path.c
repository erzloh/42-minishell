/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:00:09 by eholzer           #+#    #+#             */
/*   Updated: 2023/04/28 17:10:50 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Replace the token->cmd_arr[0] by the path of cmd if found
// Returns 0 if it succeeds
// Returns MALLOC_ERR in case of a malloc error
// Returns 1 if the command is not found
int	set_cmd_path(t_token *token, char **env_arr)
{
	char	*path_str = "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Library/Apple/usr/bin";
	char	**path_arr;
	int		ret;
	(void) env_arr;

	// Check if the cmd is already a valid path
	if (access(token->cmd_arr[0], F_OK) == 0)
	{
		token->cmd_valid = 1;
		return (0);
	}
	// path_str = ft_getenv("PATH"); // Function not availabel yet. Is it a copy? // commented for now
	if (!path_str)
		return (1); // Return MALLOC_ERR if it's a copy
	path_arr = ft_split(path_str, ':');
	if (!path_arr)
		return (print_error("to malloc path_arr", MALLOC_ERR));
	// If not a path, checks if the commands exists in one of the paths from PATH
	ret = search_cmd_in_path(path_arr, token);
	if (ret == 0)
		return (0);
	else if (ret == MALLOC_ERR)
	{
		// free(path_str); // only if get_env gives a copy
		ft_free_2d_tab((void **)path_arr);
		return (MALLOC_ERR);
	}
	else
		return (1);
}

// Return 0 if the command is found in the path_arr. Set the value of token->cmd_arr[0] to the path.
// Return 1 if the command is not found.
// Return MALLOC_ERR if there is a malloc error.
int	search_cmd_in_path(char **path_arr, t_token *token)
{
	int		i;
	char	*tmp_path;

	i = -1;
	while (path_arr[++i])
	{
		tmp_path = ft_strjoin3(path_arr[i], "/", token->cmd_arr[0]);
		if (!tmp_path)
			return (print_error("to malloc tmp_path", MALLOC_ERR));
		if (access(tmp_path, F_OK) == 0)
		{
			// free(token->cmd_arr[0]); NEEDS TO BE UNCOMMENTED WHEN MERGING WITH ALESS
			token->cmd_arr[0] = tmp_path;
			token->cmd_valid = 1;
			// free(path_str); // only if get_env gives a copy
			ft_free_2d_tab((void **)path_arr);
			return (0);
		}
	}
	free(tmp_path);
	return (1);
}
