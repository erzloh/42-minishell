/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:50:21 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/09 12:28:23 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"
#include "../incl/env_utils.h"
#include "../incl/env.h"

extern int g_status;

int	ft_setenv(const char *name, const char *value, char ***envp_copy)
{
	int			i;

	if (!ft_is_valid_name(name))
		return (-1);
	i = ft_find_index_env(name, *envp_copy);
	/* ft_printf("ind env = %i\n", i); */
	if (i >= 0)
	{
		if (ft_replace_env(name, value, envp_copy) != 0)
			return (-1);
	}
	else
	{
		if (ft_add_env(name, value, envp_copy) != 0)
			return (-1);
	}
	return (0);
}

int	ft_unsetenv(char *name, char ***envp_copy)
{
	if (!ft_is_valid_name(name) || ft_find_index_env(name, *envp_copy) < 0)
		return (-1);
	if (ft_remove_env(name, envp_copy))
		return (-1);
	return (0);
}

void	ft_get_all_env(char **envp_copy)
{
	int			i;
	char		**envp_sort;

	envp_sort = ft_str_arrdup(envp_copy);
	if (!envp_sort)
		ft_fatal_error("memory allocation error", E_ERROR_MALLOC);
	ft_str_arr_alpsort(&envp_sort);
	i = -1;
	while (envp_sort[++i])
		ft_printf("declare -x %s\n", envp_sort[i]);
}

char	*ft_getenv(const char *name, char **envp_copy)
{
	int			i;
	int			len;
	
	if (!ft_is_valid_name(name))
		return (NULL);
	if (!ft_memcmp(name, "?\0", 2))
		return (ft_itoa(g_status)); // return le status quand la variable global sera implémenté
	len = ft_strlen(name);
	i = -1;
	while (envp_copy[++i])
	{
		if (!ft_strncmp(envp_copy[i], name, len) && envp_copy[i][len] == '=')
			return (envp_copy[i]);
	}
	return (NULL);
}
