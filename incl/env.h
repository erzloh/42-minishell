/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:51:02 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/01 16:01:14 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

int		ft_setenv(const char *name, const char *value, char ***envp_copy);
int		ft_unsetenv(char *name, char ***envp_copy);
void	ft_get_all_env(char **envp_copy);
char	*ft_getenv(const char *name, char **envp_copy);

#endif