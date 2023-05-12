/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_arr_cat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:37:55 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/10 17:38:46 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

char	**ft_str_arr_cat(char **str_arr, const char *new_str)
{
	int		i;
	int		len_str;
	int		len_str_arr;
	char	**new_str_arr;

	len_str = ft_strlen(new_str);
	len_str_arr = ft_str_arr_len(str_arr);
	new_str_arr = malloc((len_str_arr + 2) * sizeof(char *));
	if (new_str_arr == NULL)
		ft_fatal_error("memory allocation error\n", E_ERROR_MALLOC);
	i = -1;
	while (++i < len_str_arr)
		new_str_arr[i] = str_arr[i];
	new_str_arr[len_str_arr] = malloc((len_str + 1) * sizeof(char));
	if (new_str_arr[len_str_arr] == NULL)
	{
		free(new_str_arr);
		ft_fatal_error("memory allocation error\n", E_ERROR_MALLOC);
	}
	new_str_arr[len_str_arr] = ft_memcpy(new_str_arr[len_str_arr],
			new_str, len_str + 1);
	new_str_arr[len_str_arr + 1] = NULL;
	free(str_arr);
	return (new_str_arr);
}
