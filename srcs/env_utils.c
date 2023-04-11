/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:52:06 by alesspal          #+#    #+#             */
/*   Updated: 2023/04/06 14:27:18 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../libft/libft.h"
#include "../incl/minishell.h"

bool	ft_is_valid_name(const char *name)
{
	if (!name || !(*name == '_' || ft_isalpha(*name)))
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

int	ft_find_index_env(const char *name)
{
	int			i;
	int			len;
	extern char	**environ;

	len = ft_strlen(name);
	i = -1;
	while (environ[++i])
	{
		if (!ft_strncmp(environ[i], name, len) && environ[i][len] == '=')
			return (i);
	}
	return (-1);
}

int	ft_replace_env(const char *name, const char *value)
{
	int			i;
	int			len;
	extern char	**environ;

	len = ft_strlen(name);
	i = -1;
	while (environ[++i])
	{
		if (!ft_strncmp(environ[i], name, len) && environ[i][len] == '=')
		{
			free(environ[i]);
			environ[i] = ft_strjoin3(name, "=", value);
			if (!environ)
				return (-1);
			return (0);
		}
	}
	return (-1);
}

int	ft_add_env(const char *name, const char *value)
{
	int			i;
	char		**new_env;
	extern char	**environ;

	i = 0;
	while (environ[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (-1);
	i = -1;
	//copy la variable environ dans env_final
	while (environ[++i])
	{
		new_env[i] = ft_strdup(environ[i]);
		if (!new_env[i])
			return (ft_free_2d_tab((void **)new_env), -1);
	}
	// donne la nouvelle valeur à la fin du tableau
	new_env[i] = ft_strjoin3(name, "=", value);
	if (!new_env[i])
		return (ft_free_2d_tab((void **)new_env), -1);
	new_env[i + 1] = NULL;
	ft_free_2d_tab((void **)environ);
	environ = new_env;
	return (0);
}

char	**ft_copy_env_except(char *name)
{
	extern char	**environ;
	char		**new_env;
	int			i;
	int			j;
	int			len;

	i = 0;
	while (environ[i])
		i++;
	new_env = malloc(sizeof(char *) * i);
	if (!new_env)
		return (NULL);
	len = ft_strlen(name);
	i = -1;
	j = 0;
	while (environ[++i])
	{
		if (!(!ft_memcmp(environ[i], name, len) && environ[i][len] == '='))
		{
			new_env[j++] = ft_strdup(environ[i]);
			if (!new_env[j - 1])
				return (ft_free_2d_tab((void **)new_env), NULL);
		}
	}
	return (new_env[j] = NULL, new_env);
}
