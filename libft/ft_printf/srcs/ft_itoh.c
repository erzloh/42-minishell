/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalumbi <apalumbi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:12:55 by alesspal          #+#    #+#             */
/*   Updated: 2022/11/24 11:05:36 by apalumbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/convert_base.h"
#include "../incl/utils.h"

int	size_of_hex_int(int nb_to_convert)
{
	int				len;
	unsigned int	u_nb_to_convert;

	len = 1;
	if (nb_to_convert >= 0)
	{
		while (nb_to_convert != 0)
		{
			nb_to_convert /= 16;
			if (nb_to_convert != 0)
				len++;
		}
	}
	else
	{
		u_nb_to_convert = nb_to_convert;
		while (u_nb_to_convert != 0)
		{
			u_nb_to_convert /= 16;
			if (u_nb_to_convert != 0)
				len++;
		}
	}
	return (len);
}

char	ft_itoch(long nb_to_convert, int in_maj)
{
	if (in_maj)
		return ("0123456789ABCDEF"[nb_to_convert % 16]);
	else
		return ("0123456789abcdef"[nb_to_convert % 16]);
}

void	calc_conv_int(long nb, char *s, int len_s, int in_maj)
{
	int	i;

	i = 0;
	while (i < len_s)
	{
		s[i] = ft_itoch(nb, in_maj);
		nb /= 16;
		i++;
	}
}

char	*ft_itoh(int nb_to_convert, int in_maj)
{
	char			*res;
	int				len;
	unsigned int	u_nb_to_convert;

	len = size_of_hex_int(nb_to_convert);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (nb_to_convert >= 0)
		calc_conv_int(nb_to_convert, res, len, in_maj);
	else
	{
		u_nb_to_convert = nb_to_convert;
		calc_conv_int(u_nb_to_convert, res, len, in_maj);
	}
	res[len] = '\0';
	ft_strev(res);
	return (res);
}
