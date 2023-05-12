/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:38:10 by alesspal          #+#    #+#             */
/*   Updated: 2022/11/18 15:27:18 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/format.h"

t_format	get_format(char c)
{
	if (c == 'c')
		return (T_CHAR);
	if (c == 's')
		return (T_STR);
	if (c == 'p')
		return (T_POINTER);
	if (c == 'd')
		return (T_DECIMAL);
	if (c == 'i')
		return (T_INT);
	if (c == 'u')
		return (T_UINT);
	if (c == 'x')
		return (T_HEX_MIN);
	if (c == 'X')
		return (T_HEX_MAJ);
	if (c == '%')
		return (T_PERCENT);
	return (T_UNDEFINED);
}
