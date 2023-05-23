/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:00:09 by marvin            #+#    #+#             */
/*   Updated: 2023/05/23 13:38:14 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

int	is_separator(char c, char sep)
{
	return (c == sep);
}

void	free_2dtab(char **tab2d)
{
	int	i;

	i = 0;
	if (!tab2d)
		return ;
	while (tab2d[i] != NULL)
	{
		free(tab2d[i]);
	}
	free(tab2d);
}

int	count_arg(const char *str, char sep)
{
	int	i;
	int	nb_word;
	int	len_str;

	i = 0;
	nb_word = 0;
	len_str = ft_strlen(str);
	while (i < len_str)
	{
		while (i < len_str && is_separator(str[i], sep))
			i++;
		while (i < len_str && !is_separator(str[i], sep))
			i++;
		if (is_separator(str[i - 1], sep))
			break ;
		nb_word++;
		i++;
	}
	return (nb_word);
}

char	*get_word(const char *str, char sep, int *start, int len_str)
{
	int		i;
	int		j;
	int		len_word;
	char	*word;

	i = *start;
	while (i < len_str && is_separator(str[i], sep))
		i++;
	j = i;
	while (i < len_str && !is_separator(str[i], sep))
		i++;
	len_word = i - j;
	*start = i;
	word = malloc((len_word + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len_word)
	{
		word[i] = str[j + i];
		i++;
	}
	word[len_word] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len_str;
	int		nb_word_cpt;
	int		nb_word_tot;
	char	**split;

	nb_word_tot = count_arg(s, c);
	split = malloc((nb_word_tot + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	len_str = ft_strlen(s);
	i = 0;
	nb_word_cpt = 0;
	while (nb_word_cpt < nb_word_tot)
	{
		split[nb_word_cpt] = get_word(s, c, &i, len_str);
		if (!split[nb_word_cpt])
			return (NULL);
		nb_word_cpt++;
	}
	split[nb_word_tot] = NULL;
	return (split);
}
