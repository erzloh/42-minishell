/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:09:05 by alesspal          #+#    #+#             */
/*   Updated: 2023/04/06 14:25:38 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../libft/libft.h"
#include "../incl/minishell.h"

/// @brief initialize the variable environ
/// @brief CALL THIS FUNCTION BEFORE WANTING TO MAKE 
/// @brief A MODIFICATION TO THE ENVIRONMENT VARIABLE !!!
/// @param void
/// @return 0 : for no error, 1 : error of malloc
int	init_env(void)
{
	int			i;
	char		**new_env;
	extern char	**environ;
	static int	is_already_init;

	if (is_already_init)
		return (0);
	i = 0;
	while (environ[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return (-1);
	i = -1;
	while (environ[++i])
	{
		new_env[i] = ft_strdup(environ[i]);
		if (!new_env)
			return (ft_free_2d_tab((void **)new_env), -1);
	}
	new_env[i] = NULL;
	environ = new_env;
	is_already_init = 1;
	return (0);
}

int	ft_setenv(const char *name, const char *value)
{
	int			i;
	extern char	**environ;

	if (!name || !ft_strlen(name) || !ft_is_valid_name(name))
		return (-1);
	if (init_env() != 0)
		return (-1);
	i = ft_find_index_env(name);
	if (i >= 0)
	{
		if (ft_replace_env(name, value) != 0)
			return (-1);
	}
	else
	{
		if (ft_add_env(name, value) != 0)
			return (-1);
	}
	return (0);
}

int	ft_unsetenv(char *name)
{
	extern char	**environ;
	char		**new_env;

	if (!name || !ft_strlen(name) || !ft_is_valid_name(name)
		|| ft_find_index_env(name) < 0 || init_env() != 0)
		return (-1);
	new_env = ft_copy_env_except(name);
	if (!new_env)
		return (-1);
	ft_free_2d_tab((void **)environ);
	environ = new_env;
	return (0);
}

void	ft_get_all_env(void)
{
	int			i;
	extern char	**environ;

	i = -1;
	while (environ[++i] != NULL)
		ft_printf("%s\n", environ[i]);
}

char	*ft_getenv(const char *name)
{
	if (!name || !ft_strlen(name))
		return (NULL);
	if (!ft_memcmp(name, "?\0", 2))
		return (NULL); // return le status quand la variable global sera implémenté
	return (getenv(name));
}
