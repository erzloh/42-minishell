/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_manager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:39:13 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/22 17:26:36 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTE_MANAGER_H
# define QUOTE_MANAGER_H

# include <stdbool.h>

bool	check_unmatched_quotes(char *str);
void	update_quote_status(char cur_char, char *cur_quote);
char	*ft_remove_quotes(char *str);

#endif