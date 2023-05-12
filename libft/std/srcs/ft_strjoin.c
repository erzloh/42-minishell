/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:43:58 by marvin            #+#    #+#             */
/*   Updated: 2023/03/30 11:34:08 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		len_s1;
	int		len_s2;
	char	*str;

	if (!s2)
		return (NULL);
	if (s1)
		len_s1 = ft_strlen(s1);
	else
		len_s1 = 0;
	len_s2 = ft_strlen(s2);
	str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	if (s1)
		while (++i < len_s1)
			str[i] = s1[i];
	i = -1;
	while (++i < len_s2)
		str[len_s1 + i] = s2[i];
	str[len_s1 + len_s2] = '\0';
	return (str);
}
