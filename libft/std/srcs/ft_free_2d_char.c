/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:47:24 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/22 15:35:35 by alesspal         ###   ########.fr       */
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
		/* printf("Freeing pointer: %p\n", c[i]); */
		free(c[i]);
	}
	/* printf("Freeing tab: %p\n", c); */
	free(c);
}