/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:53:25 by marvin            #+#    #+#             */
/*   Updated: 2022/12/08 12:09:36 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std.h"

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
