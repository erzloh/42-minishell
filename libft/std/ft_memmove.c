/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:18:33 by marvin            #+#    #+#             */
/*   Updated: 2022/12/08 12:09:36 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest2;
	const char	*src2;

	dest2 = dest;
	src2 = src;
	if (!dest2 && !src2)
		return (NULL);
	if (dest2 > src2)
	{
		while (n > 0)
		{
			n--;
			dest2[n] = src2[n];
		}
	}
	else if (dest2 < src2)
	{
		dest2 = ft_memcpy(dest2, src2, n);
	}
	return (dest);
}
