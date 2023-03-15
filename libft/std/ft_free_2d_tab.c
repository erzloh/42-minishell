/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:34:39 by alesspal          #+#    #+#             */
/*   Updated: 2023/02/28 15:44:48 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std.h"

void	ft_free_2d_tab(int **tab, int row)
{
	int	i;

	if (!tab)
		return ;
	i = -1;
	while (++i < row)
	{
		if (tab[i])
			free(tab[i]);
	}
	free(tab);
}
