/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalumbi <apalumbi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:58:51 by alesspal          #+#    #+#             */
/*   Updated: 2022/12/06 13:07:01 by apalumbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	get_pow2(long n, int acc)
{
	if (n == 0)
		return (acc);
	else if (n > 9 || n < -9)
		return (get_pow2(n / 10, ++acc));
	else
		return (acc);
}

void	set_nbr2(char *s, long n, int sign)
{
	int	pow;

	if (n != 0)
		set_nbr2(s, n / 10, sign);
	pow = get_pow2(n, 1);
	if (pow == 0)
		s[0] = '0';
	if (pow > 0 && sign > 0)
		s[pow - 1] = "0123456789"[n % 10];
	else if (pow > 0 && sign < 0)
		s[pow - sign - 1] = "0123456789"[n % 10];
	if (pow == 1 && sign < 0)
		s[0] = '-';
}

char	*ft_uitoa(unsigned int n)
{
	char	*nbr;
	long	converted;
	int		nbr_len;

	converted = n;
	nbr_len = get_pow2(converted, 1);
	nbr = malloc(sizeof(*nbr) * (nbr_len + 1));
	if (nbr == NULL)
		return (NULL);
	set_nbr2(nbr, converted, 1);
	nbr[nbr_len] = '\0';
	return (nbr);
}
