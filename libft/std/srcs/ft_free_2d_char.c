/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:47:24 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/01 16:50:05 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

void	ft_free_2d_char(char **c)
{
	int i;

	if (!c)
		return;
	i = -1;
	while (c[++i]) {
		/* printf("Freeing pointer: %p\n", tab[i]); */
		free(c[i]);
	}
	/* printf("Freeing tab: %p\n", tab); */
	free(c);
}