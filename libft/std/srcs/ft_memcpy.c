/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:40:54 by marvin            #+#    #+#             */
/*   Updated: 2023/03/16 17:02:58 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest2;
	const char	*src2;

	if (dest == src)
		return (NULL);
	dest2 = (char *)dest;
	src2 = (const char *)src;
	i = -1;
	while (++i < n)
		dest2[i] = src2[i];
	return (dest);
}
