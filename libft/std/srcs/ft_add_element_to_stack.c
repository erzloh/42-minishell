/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_element_to_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:53:17 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/16 16:59:42 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

t_stack	*ft_add_t_stack_element(t_stack *stack, int element)
{
	int		i;
	int		*tab;

	if (!stack)
		stack = ft_malloc_stack(1);
	else
		stack->size++;
	tab = malloc(sizeof(int) * (stack->size));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < stack->size - 1)
		tab[i] = stack->tab[i];
	tab[i] = element;
	free(stack->tab);
	stack->tab = tab;
	stack->size++;
	return (stack);
}
