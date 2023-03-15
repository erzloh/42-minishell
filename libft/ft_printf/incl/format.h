/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalumbi <apalumbi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:02:54 by alesspal          #+#    #+#             */
/*   Updated: 2022/12/06 15:57:44 by apalumbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

typedef enum eformat{
	T_CHAR = 0,
	T_STR,
	T_POINTER,
	T_DECIMAL,
	T_INT,
	T_UINT,
	T_HEX_MIN,
	T_HEX_MAJ,
	T_PERCENT,
	T_UNDEFINED,
}t_format;

t_format	get_format(char c);

#endif
