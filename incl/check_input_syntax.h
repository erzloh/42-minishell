/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_syntax.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:33:58 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/22 17:26:47 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_INPUT_SYNTAX_H
# define CHECK_INPUT_SYNTAX_H

# include <stdbool.h>

bool	ft_is_pipe(int c);
bool	ft_is_redirection(int c);
bool	ft_is_too_many_redirects(char **f_input, int i, int len, int cnt_red);
bool	ft_is_same_redirection(char cur_redirection, char prev_redirection);
bool	ft_is_valid_pipe(char **f_input, int i);
bool	ft_is_valid_redirection(char **f_input, int i);

bool	ft_is_empty_cmd(char *input);
bool	ft_is_correct_syntax(char *input);
void	ft_print_syntax_error(char *token_error);

#endif