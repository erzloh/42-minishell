/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:44:28 by marvin            #+#    #+#             */
/*   Updated: 2023/03/16 17:02:58 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		last_occurrence;
	char	chr;

	i = 0;
	last_occurrence = -1;
	chr = c;
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			last_occurrence = i;
		i++;
	}
	if (last_occurrence != -1)
		return ((char *)str + last_occurrence);
	if (chr == '\0')
		return ((char *)str + i);
	return (NULL);
}
