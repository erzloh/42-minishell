/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:52:34 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/23 12:43:08 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/lexer_utils.h"
#include "../incl/quote_manager.h"

int	ft_count_arg(const char *str)
{
	int		i;
	int		nb_word;
	char	cur_quote;

	if (!str)
		return (0);
	nb_word = 0;
	cur_quote = 0;
	i = -1;
	while (str[++i])
	{
		update_quote_status(str[i], &cur_quote);
		if (!cur_quote)
			update_word_count(str, i, &nb_word);
	}
	if (!ft_is_white_space(str[i - 1]) && !ft_is_pipe_or_redirec(str[i - 1]))
		nb_word++;
	return (nb_word);
}

char	*ft_get_next_arg(const char *str, int *start)
{
	int		i;
	char	cur_quote;
	char	*word;

	cur_quote = 0;
	i = *start;
	if (!str || !str[i])
		return (NULL);
	while (ft_is_white_space(str[i]))
		i++;
	*start = i;
	while (str[i])
	{
		update_quote_status(str[i], &cur_quote);
		if (!cur_quote)
		{
			word = handle_character(str, i, start);
			if (word)
				return (word);
		}
		i++;
	}
	return (create_word_and_update_start(str, i, start));
}

char	**ft_lexer(char const *s)
{
	int		i;
	int		nb_word_cpt;
	int		nb_word_tot;
	char	**split;

	if (!s)
		return (NULL);
	nb_word_tot = ft_count_arg(s);
	split = malloc((nb_word_tot + 1) * sizeof(char *));
	if (!split)
		ft_fatal_error("memory allocation error4\n", E_ERROR_MALLOC);
	i = 0;
	nb_word_cpt = 0;
	while (nb_word_cpt < nb_word_tot)
	{
		split[nb_word_cpt] = ft_get_next_arg(s, &i);
		if (!split[nb_word_cpt])
			return (NULL);
		nb_word_cpt++;
	}
	split[nb_word_tot] = NULL;
	return (split);
}
