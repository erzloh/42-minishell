/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_2d_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:28:44 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/16 17:02:58 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

int	**ft_malloc_2d_tab(int row, int col)
{
	int	i;
	int	**tab;

	tab = malloc(sizeof(int *) * row);
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < row)
	{
		tab[i] = malloc(sizeof(int) * col);
		if (!tab[i])
		{
			ft_free_2d_tab(tab, 4);
			return (NULL);
		}			
	}
	return (tab);
}
