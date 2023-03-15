/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:58:36 by marvin            #+#    #+#             */
/*   Updated: 2022/12/08 12:10:14 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	size_t	length;
	char	*str;

	i = 0;
	len_s = ft_strlen(s);
	if (len_s > start + len)
		length = len;
	else if (start > len_s || len_s == 0)
		length = 0;
	else
		length = len_s - start;
	str = malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i] != '\0' && i < length)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
