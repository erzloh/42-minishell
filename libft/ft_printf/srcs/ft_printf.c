/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:56:05 by alesspal          #+#    #+#             */
/*   Updated: 2023/03/30 11:34:08 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/format.h"
#include "../incl/update_aff.h"
#include "../incl/ft_printf.h"

int	update_line(const char *str, int len_str, va_list *ap)
{
	int	i;
	int	len_updated;

	i = -1;
	len_updated = 0;
	while (++i < len_str)
	{
		if (str[i] == '%')
		{
			if (++i < len_str && get_format(str[i]) != T_UNDEFINED)
				len_updated += update_aff(*&ap, get_format(str[i]));
			else
			{
				ft_putchar_fd(str[i - 1], 1);
				if (i < len_str)
					ft_putchar_fd(str[i], 1);
			}
		}
		else
			ft_putchar_fd(str[i], 1);
	}
	return (len_updated);
}

int	ft_printf(const char *str, ...)
{
	int		len_str;
	int		len_final;
	va_list	ap;

	len_final = 0;
	len_str = ft_strlen(str);
	va_start(ap, str);
	len_final = update_line(str, len_str, &ap);
	va_end(ap);
	len_final += len_str;
	return (len_final);
}

/* int	ft_printf(const char *str, ...)
{
	int		i;
	int		len_str;
	int		len_final;
	va_list	ap;

	i = -1;
	len_final = 0;
	len_str = ft_strlen(str);
	va_start(ap, str);
	while (++i < len_str)
		if (str[i] == '%')
			if (++i < len_str && get_format(str[i]) != T_UNDEFINED)
				len_final += update_aff(&ap, get_format(str[i]));
			else
			{
				ft_putchar_fd(str[i - 1], 1);
				if (i < len_str)
					ft_putchar_fd(str[i], 1);
			}
		else
			ft_putchar_fd(str[i], 1);
	va_end(ap);
	len_final += len_str;
	return (len_final);
} */
