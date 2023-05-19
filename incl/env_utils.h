/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:52:24 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/17 14:35:56 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "../libft/libft.h"

bool	ft_is_valid_env_name(const char *name);
int		ft_find_index_env(const char *name, char **envp_copy);
int		ft_replace_env(const char *name, const char *value, char ***envp_copy);
int		ft_add_env(const char *name, const char *value, char ***envp_copy);
int		ft_remove_env(char *name, char ***envp_copy);

#endif