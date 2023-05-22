/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:34:39 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/22 17:25:40 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

void	ft_free_2d_int(int **tab, int row)
{
	int	i;

	if (!tab)
		return ;
	i = -1;
	while (i < row)
		free(tab[i]);
	free(tab);
}
