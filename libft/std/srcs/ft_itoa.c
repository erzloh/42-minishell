/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:27:49 by marvin            #+#    #+#             */
/*   Updated: 2023/03/16 17:02:58 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

int	get_pow(long n, int acc)
{
	if (n == 0)
		return (acc);
	else if (n > 9 || n < -9)
		return (get_pow(n / 10, ++acc));
	else
		return (acc);
}

void	set_nbr(char *s, long n, int sign)
{
	int	pow;

	if (n != 0)
		set_nbr(s, n / 10, sign);
	pow = get_pow(n, 1);
	if (pow == 0)
		s[0] = '0';
	if (pow > 0 && sign > 0)
		s[pow - 1] = "0123456789"[n % 10];
	else if (pow > 0 && sign < 0)
		s[pow - sign - 1] = "0123456789"[n % 10];
	if (pow == 1 && sign < 0)
		s[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*nbr;
	long	converted;
	int		nbr_len;
	int		sign;

	converted = n;
	sign = 1;
	nbr_len = get_pow(converted, 1);
	if (n < 0)
	{
		nbr_len++;
		sign = -1;
		converted *= -1;
	}
	nbr = malloc(sizeof(*nbr) * (nbr_len + 1));
	if (nbr == NULL)
		return (NULL);
	set_nbr(nbr, converted, sign);
	nbr[nbr_len] = '\0';
	return (nbr);
}
