/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalumbi <apalumbi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:41:07 by alesspal          #+#    #+#             */
/*   Updated: 2022/12/06 13:38:49 by apalumbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/utils.h"

void	ft_strev(char *str)
{
	int		i;
	int		len;
	char	temp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}
