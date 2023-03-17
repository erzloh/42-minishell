/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:09:05 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/17 18:41:14 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <string.h>

int	ft_is_dollar(int c)
{
	return (c == '$');
}

int my_setenv(const char *name, const char *value, int overwrite)
{
	char extern **environ;
    char *var, **environ_copy;
    size_t len = strlen(name) + strlen(value) + 2;
    int i = 0;

    /* Vérifier que le nom de la variable n'est pas vide */
    if (!name || !*name) {
        return -1;
    }

    /* Vérifier que le nom de la variable ne contient pas '=' */
    if (strchr(name, '=') != NULL) {
        return -1;
    }

    /* Rechercher si la variable existe déjà */
    for (i = 0; environ[i]; i++) {
        if (strncmp(environ[i], name, strlen(name)) == 0 && environ[i][strlen(name)] == '=') {
            if (!overwrite) {
                return 0;
            }
            break;
        }
    }

    /* Allouer de la mémoire pour stocker la variable */
    var = malloc(len);
    if (!var) {
        return -1;
    }
    snprintf(var, len, "%s=%s", name, value);

    /* Copier le tableau d'environnement dans une nouvelle zone mémoire */
    environ_copy = malloc((i + 2) * sizeof(char*));
    if (!environ_copy) {
        free(var);
        return -1;
    }
    memcpy(environ_copy, environ, i * sizeof(char*));
    environ_copy[i] = var;
    environ_copy[i + 1] = NULL;

    /* Remplacer le tableau d'environnement par la copie */
    environ = environ_copy;

    return 0;
}

int	ft_setenv(const char *name, const char *value)
{
	int			i;
	int			len;
	char		**env_final;
	extern char	**environ;
	static int	is_malloc;
	
	if (!name || !ft_strlen(name) || ft_strchr(name, '=') != NULL)
		return (-1);
	len = ft_strlen(name);
	i = 0;
	while (environ[i])
	{
		if (!ft_strncmp(environ[i], name, len) 
			&& environ[i][len] == '=')
		{
			free(environ[i]);
			environ[i] = ft_strjoin3(name, "=", value);
			return (0);
		}
		i++;
	}
	env_final = malloc(sizeof(char *) * (i + 2));
	if (!env_final)
		return (-1);
	i = -1;
	while (environ[++i])
	{
		env_final[i] = ft_strdup(environ[i]);
		if (!env_final[i])
		{
			ft_free_2d_tab((void **)env_final);
			return (-1);
		}
	}
	env_final[i] = ft_strjoin3(name, "=", value);
	env_final[i + 1] = NULL;
	if (is_malloc)
		ft_free_2d_tab((void **)environ);
	environ = env_final;
	is_malloc = 1;
	return (0);
}

int	ft_unsetenv(char *name)
{
	int			i;
	int			len;
	/* char		**env_final; */
	extern char **environ;

	len = ft_strlen(name);
	i = -1;
	while (environ[++i])
	{
		if (!ft_memcmp(environ[i], name, len))
		{
			free(environ[i]);
			environ[i] = environ[i + 1];
		}
	}
	return (0);
}

void	ft_get_all_env()
{
	int			i;
	extern char	**environ;
	
	i = -1;
	while(environ[++i] != NULL)
		ft_printf("%s\n", environ[i]);
}

const char	*ft_getenv(const char *name)
{
	
	if (!name || !ft_strlen(name))
		return (NULL);
	return (getenv(name));
}

char	*ft_findenv(const char *input)
{
	int		i;
	int		j;
	int		len;

	len = ft_strlen(input);
	i = -1;
	while (++i < len)
	{
		if (ft_is_dollar(input[i]))
		{
			j = 0;
			while (++i < len)
			{
				if (ft_is_white_space(input[i]))
					break;
				j++;
			}
			return (ft_strndup(&input[i - j], j));
		}
	}
	return (NULL);
}