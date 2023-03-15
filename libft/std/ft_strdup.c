/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:33:05 by marvin            #+#    #+#             */
/*   Updated: 2022/12/08 12:09:36 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		len_str;
	char	*dest;

	i = 0;
	len_str = ft_strlen(str);
	dest = malloc((len_str + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len_str)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
