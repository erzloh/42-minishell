/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:08:38 by marvin            #+#    #+#             */
/*   Updated: 2023/03/30 11:34:08 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;
	size_t	offset_dest;
	size_t	len_final;

	i = 0;
	len_src = ft_strlen(src);
	offset_dest = ft_strlen(dest);
	if (size == 0)
		return (len_src);
	else if (size < offset_dest)
		len_final = len_src + size;
	else
		len_final = len_src + offset_dest;
	i = 0;
	while (i < len_src && offset_dest < size - 1)
	{
		dest[offset_dest] = src[i];
		offset_dest++;
		i++;
	}
	dest[offset_dest] = '\0';
	return (len_final);
}
