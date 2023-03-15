/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:04:27 by marvin            #+#    #+#             */
/*   Updated: 2022/12/08 12:10:14 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	start_ignored;
	int	nb_char_ignored;
	int	len_s1;

	start_ignored = 0;
	nb_char_ignored = 0;
	len_s1 = ft_strlen(s1);
	if (!len_s1)
		return (ft_strdup("\0"));
	i = -1;
	while (ft_strchr(set, s1[++i]))
		nb_char_ignored++;
	start_ignored = nb_char_ignored;
	i = len_s1;
	while (ft_strchr(set, s1[--i]))
		nb_char_ignored++;
	return (ft_substr(s1, start_ignored, len_s1 - nb_char_ignored));
}
