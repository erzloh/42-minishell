/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:10:56 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/16 17:02:58 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

t_stack	*ft_malloc_stack(int len_to_allocate)
{
	t_stack	*stk;

	stk = NULL;
	if (len_to_allocate < 1)
		return (NULL);
	stk = malloc(sizeof(t_stack));
	if (!stk)
		return (NULL);
	stk->tab = malloc(sizeof(int) * len_to_allocate);
	if (!stk->tab)
	{
		free(stk);
		return (NULL);
	}
	stk->lenght_allocated = len_to_allocate;
	stk->size = 0;
	return (stk);
}

t_stack	*ft_malloc_and_cpy_stack(t_stack *stack)
{
	int		i;
	t_stack	*stk;

	if (!stack)
		return (NULL);
	stk = ft_malloc_stack(stack->size);
	if (!stk)
		return (NULL);
	i = -1;
	while (++i < stack->size)
		stk->tab[i] = stack->tab[i];
	stk->size = stack->size;
	return (stk);
}
