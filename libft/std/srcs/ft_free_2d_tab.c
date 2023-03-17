/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:34:39 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/17 18:37:10 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

void ft_free_2d_tab(void **tab)
{
    int i;

    if (!tab)
        return;
    i = -1;
    while (tab[++i]) {
        if (tab[i]) {
            /* printf("Freeing pointer: %p\n", tab[i]); */
            free(tab[i]);
        }
    }
    /* printf("Freeing tab: %p\n", tab); */
    free(tab);
}
