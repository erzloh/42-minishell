/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_aff.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:45:13 by alesspal          #+#    #+#             */
/*   Updated: 2022/11/18 15:07:57 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_AFF_H
# define UPDATE_AFF_H

# include <stdarg.h>
# include "format.h"

int	aff_decimal(va_list *ap, t_format format);
int	aff_char(va_list *ap, t_format format);
int	aff_hex(va_list *ap, int in_maj);
int	aff_pointer(va_list *ap);
int	update_aff(va_list *ap, t_format format);

#endif