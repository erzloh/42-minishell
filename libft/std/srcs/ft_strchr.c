/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:53:25 by marvin            #+#    #+#             */
/*   Updated: 2023/03/16 17:02:58 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	chr;

	i = 0;
	chr = c;
	while (str[i] != '\0' && str[i] != chr)
		i++;
	if (str[i] != '\0' || chr == '\0')
		return ((char *)str + i);
	return (NULL);
}
