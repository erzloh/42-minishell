/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:20:50 by marvin            #+#    #+#             */
/*   Updated: 2023/03/30 11:34:08 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	len_to_find;

	i = -1;
	len_to_find = ft_strlen(to_find);
	if (len_to_find == 0)
		return ((char *)str);
	while (str[++i] != '\0' && i + len_to_find <= len)
		if (!ft_strncmp(str + i, to_find, len_to_find))
			return ((char *)(str + i));
	return (NULL);
}
