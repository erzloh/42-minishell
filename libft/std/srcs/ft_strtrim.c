/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:04:27 by marvin            #+#    #+#             */
/*   Updated: 2023/04/06 15:31:31 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

char	*ft_strtrim(char *s1, char const *set)
{
	int		i;
	int		start_ignored;
	int		nb_char_ignored;
	int		len_s1;
	char	*result;

	if (!s1)
		return (NULL);
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
	result = ft_substr(s1, start_ignored, len_s1 - nb_char_ignored);
	free (s1);
	return (result);
}
