/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:50:15 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/30 11:34:08 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

char	*ft_strndup(const char *src, size_t n)
{
	int		ret_strlcpy;
	char	*dst;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (n < src_len)
		src_len = n;
	dst = malloc(src_len + 1);
	if (dst == NULL)
		return (NULL);
	ret_strlcpy = ft_strlcpy(dst, src, src_len + 1);
	if (!ret_strlcpy)
	{
		free(dst);
		dst = NULL;
	}
	return (dst);
}
