/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:50:17 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/10 17:21:14 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

bool	ft_is_valid_name(const char *name)
{
	if (!name || !(ft_isalpha(*name) || *name == '_' || *name == '?') || !ft_strlen(name))
		return (false);
	name++;
	while (*name)
	{
		if (!ft_isalnum(*name) && *name != '_')
			return (false);
		name++;
	}
	return (true);
}

int	ft_find_index_env(const char *name, char **envp_copy)
{
	int			i;
	int			len;

	if (!name || !(*envp_copy))
		return (-1);
	len = ft_strlen(name);
	i = -1;
	while (envp_copy[++i])
	{
		if (!ft_strncmp(envp_copy[i], name, len) && envp_copy[i][len] == '=')
			return (i);
	}
	return (-1);
}

int	ft_replace_env(const char *name, const char *value, char ***envp_copy)
{
	int			i;
	int			len;

	if (!name || !(*envp_copy))
		return (-1);
	len = ft_strlen(name);
	i = -1;
	while ((*envp_copy)[++i])
	{
		if (!ft_strncmp((*envp_copy)[i], name, len) && (*envp_copy)[i][len] == '=')
		{
			free((*envp_copy)[i]);
			(*envp_copy)[i] = ft_strjoin3(name, "=", value);
			if (!(*envp_copy)[i])
				ft_fatal_error("memory allocation error", E_ERROR_MALLOC);
			return (0);
		}
	}
	return (-1);
}

int	ft_add_env(const char *name, const char *value, char ***envp_copy)
{
	int			i;
	char		**new_env;

	if (!name || !(*envp_copy))
		return (-1);
	i = 0;
	while ((*envp_copy)[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		ft_fatal_error("memory allocation error", E_ERROR_MALLOC);
	i = -1;
	while ((*envp_copy)[++i])
	{
		new_env[i] = ft_strdup((*envp_copy)[i]);
		if (!new_env[i])
			ft_fatal_error("memory allocation error", E_ERROR_MALLOC);
	}
	new_env[i] = ft_strjoin3(name, "=", value);
	if (!new_env[i])
		ft_fatal_error("memory allocation error", E_ERROR_MALLOC);
	new_env[i + 1] = NULL;
	ft_free_2d_char(*envp_copy);
	*envp_copy = new_env;
	return (0);
}

int	ft_remove_env(char *name, char ***envp_copy)
{
	char		**new_env;
	int			i;
	int			j;
	int			len;

	if (!name || !(*envp_copy))
		return (-1);
	i = 0;
	while ((*envp_copy)[i])
		i++;
	new_env = malloc(sizeof(char *) * i);
	if (!new_env)
		ft_fatal_error("memory allocation error", E_ERROR_MALLOC);
	len = ft_strlen(name);
	i = -1;
	j = 0;
	while ((*envp_copy)[++i])
	{
		if (!(!ft_memcmp((*envp_copy)[i], name, len) && (*envp_copy)[i][len] == '='))
		{
			new_env[j++] = ft_strdup((*envp_copy)[i]);
			if (!new_env[j - 1])
				ft_fatal_error("memory allocation error", E_ERROR_MALLOC);
		}
	}
	new_env[j] = NULL;
	ft_free_2d_char(*envp_copy);
	return (*envp_copy = new_env, 0);
}
