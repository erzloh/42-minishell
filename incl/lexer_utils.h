/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:28:37 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/15 17:17:34 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_UTILS_H
# define LEXER_UTILS_H

int		ft_is_pipe_or_redirec(int c);
void	update_quote_status(char cur_char, char *cur_quote);
void	update_word_count(const char *str, int i, int *nb_word);
char	*create_word_and_update_start(const char *str, int i, int *start);
char	*handle_character(const char *str, int i, int *start);

#endif