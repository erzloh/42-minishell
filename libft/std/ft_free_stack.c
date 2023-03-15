/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:07:39 by alesspal          #+#    #+#             */
/*   Updated: 2023/02/07 12:41:00 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std.h"

void	free_stack(t_stack *to_freed)
{
	if (!to_freed)
		return ;
	if (to_freed->tab)
		free(to_freed->tab);
	free(to_freed);
}
