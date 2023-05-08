/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:34:39 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/01 16:54:49 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

void	ft_free_2d_int(int **tab, int row)
{
	int i;

	if (!tab)
		return;
	i = -1;
	while (i < row) {
		/* printf("Freeing pointer: %p\n", tab[i]); */
		free(tab[i]);
	}
	/* printf("Freeing tab: %p\n", tab); */
	free(tab);
}
