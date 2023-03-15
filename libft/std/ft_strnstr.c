/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:20:50 by marvin            #+#    #+#             */
/*   Updated: 2022/12/08 12:10:01 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std.h"

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
