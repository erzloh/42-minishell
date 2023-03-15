/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:14:48 by marvin            #+#    #+#             */
/*   Updated: 2022/12/08 12:10:01 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len_s;
	char			*str;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	str = malloc((len_s + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len_s)
		str[i] = f(i, s[i]);
	str[i] = '\0';
	return (str);
}
