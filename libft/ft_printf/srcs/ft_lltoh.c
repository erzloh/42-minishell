/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalumbi <apalumbi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:11:50 by alesspal          #+#    #+#             */
/*   Updated: 2022/11/24 11:06:37 by apalumbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/convert_base.h"
#include "../incl/utils.h"

int	size_of_hex_ulong(unsigned long nb_to_convert)
{
	int				len;

	len = 1;
	while (nb_to_convert != 0)
	{
		nb_to_convert /= 16;
		if (nb_to_convert != 0)
			len++;
	}
	return (len);
}

char	ft_ultoch(unsigned long long nb_to_convert, int in_maj)
{
	if (in_maj)
		return ("0123456789ABCDEF"[nb_to_convert % 16]);
	else
		return ("0123456789abcdef"[nb_to_convert % 16]);
}

void	calc_conv_ulong(unsigned long long nb, char *s, int len_s, int in_maj)
{
	int	i;

	i = 0;
	while (i < len_s)
	{
		s[i] = ft_ultoch(nb, in_maj);
		nb /= 16;
		i++;
	}
}

char	*ft_ultoh(unsigned long nb_to_convert, int in_maj)
{
	char					*res;
	int						len;
	unsigned long long		ll_nb_to_convert;

	ll_nb_to_convert = nb_to_convert;
	len = size_of_hex_ulong(ll_nb_to_convert);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	calc_conv_ulong(ll_nb_to_convert, res, len, in_maj);
	res[len] = '\0';
	ft_strev(res);
	return (res);
}
