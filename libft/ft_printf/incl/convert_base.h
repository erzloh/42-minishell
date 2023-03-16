/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:40:56 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/16 17:12:26 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_BASE_H
# define CONVERT_BASE_H

# include "../../std/incl/std.h"

char			*ft_itoh(int nb_to_convert, int in_maj);
char			*ft_ultoh(unsigned long nb_to_convert, int in_maj);
char			*ft_uitoa(unsigned int n);

#endif
