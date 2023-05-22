/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_arr_alpsort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:00:31 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/22 17:30:07 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

void	ft_str_arr_alpsort(char ***str_arr)
{
	int			i;
	int			j;
	int			len_envp;
	char		*temp;
	char		**s_sort;

	s_sort = *str_arr;
	if (!s_sort)
		return ;
	len_envp = ft_str_arr_len(*str_arr);
	i = -1;
	while (++i < len_envp - 1)
	{
		j = -1;
		while (++j < len_envp - i - 1)
		{
			if (ft_memcmp(s_sort[j], s_sort[j + 1], ft_strlen(s_sort[j])) > 0)
			{
				temp = s_sort[j];
				s_sort[j] = s_sort[j + 1];
				s_sort[j + 1] = temp;
			}
		}
	}
}
