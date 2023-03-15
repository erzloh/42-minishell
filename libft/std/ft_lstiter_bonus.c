/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:27:52 by marvin            #+#    #+#             */
/*   Updated: 2022/12/08 12:09:36 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*new_lst;

	new_lst = lst;
	while (new_lst)
	{
		f(new_lst->content);
		new_lst = new_lst->next;
	}
}
