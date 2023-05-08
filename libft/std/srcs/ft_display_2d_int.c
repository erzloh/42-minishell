/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_2d_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:46:27 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/01 16:48:17 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/incl/ft_printf.h"

void	display_2d_int(int **tab, int row, int col)
{
	int	i;
	int	j;

	i = -1;
	if (!tab || row < 1 || col < 1)
		return ;
	while (++i < row)
	{
		j = -1;
		while (++j < col)
		{
			ft_printf("%i", tab[i][j]);
			if (j != col - 1)
				ft_printf(", ");
		}
		ft_printf("\n");
	}
}
