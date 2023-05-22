/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_arrdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:46:21 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/22 17:25:59 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

char	**ft_str_arrdup(char **str_arr)
{
	int		i;
	char	**str_arr_copy;

	i = 0;
	while (str_arr[i])
		i++;
	str_arr_copy = malloc(sizeof(char *) * i + 1);
	if (!str_arr_copy)
		return (NULL);
	i = -1;
	while (str_arr[++i])
	{
		str_arr_copy[i] = ft_strdup(str_arr[i]);
		if (!str_arr_copy[i])
		{
			ft_free_2d_char(str_arr_copy);
			return (NULL);
		}
	}
	str_arr_copy[i] = NULL;
	return (str_arr_copy);
}
