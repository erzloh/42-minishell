/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_aff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:44:59 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/30 11:34:08 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/convert_base.h"
#include "../incl/update_aff.h"
#include "../incl/utils.h"

int	aff_decimal(va_list *ap, t_format format)
{
	long	nb;
	int		len;
	char	*str;

	if (format == T_INT || format == T_DECIMAL)
	{
		nb = va_arg(*ap, int);
		str = ft_itoa(nb);
	}
	else
	{
		nb = va_arg(*ap, unsigned int);
		str = ft_uitoa(nb);
	}
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str) - 2;
	free(str);
	return (len);
}

int	aff_char(va_list *ap, t_format format)
{
	int		len;
	char	*str;

	len = -1;
	if (format == T_STR)
	{
		str = va_arg(*ap, char *);
		if (!str)
		{
			ft_putstr_fd("(null)", 1);
			return (4);
		}
		ft_putstr_fd(str, 1);
		len = ft_strlen(str) - 2;
	}
	else if (format == T_CHAR)
		ft_putchar_fd(va_arg(*ap, int), 1);
	else
		ft_putchar_fd('%', 1);
	return (len);
}

int	aff_hex(va_list *ap, int in_maj)
{
	int		nb;
	int		len;
	char	*str;

	nb = va_arg(*ap, int);
	str = ft_itoh(nb, in_maj);
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str) - 2;
	free(str);
	return (len);
}

int	aff_pointer(va_list *ap)
{
	int		len_hex;
	long	nb;
	char	*str;

	nb = va_arg(*ap, unsigned long);
	str = ft_ultoh(nb, 0);
	if (!str)
		return (0);
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	len_hex = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free (str);
	return (len_hex);
}

int	update_aff(va_list *ap, t_format format)
{
	if (format == T_HEX_MIN)
		return (aff_hex(*&ap, 0));
	else if (format == T_HEX_MAJ)
		return (aff_hex(*&ap, 1));
	else if (format == T_INT || format == T_DECIMAL || format == T_UINT)
		return (aff_decimal(*&ap, format));
	else if (format == T_POINTER)
		return (aff_pointer(*&ap));
	else if (format == T_CHAR || format == T_PERCENT || format == T_STR)
		return (aff_char(*&ap, format));
	return (0);
}
