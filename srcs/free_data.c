/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:55:37 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/23 13:53:00 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	ft_free_data(t_data *data)
{
	if (data->input)
	{
		free(data->input);
		data->input = NULL;
	}
	if (data->formatted_input)
	{
		ft_free_2d_char(data->formatted_input);
		data->formatted_input = NULL;
	}
	if (data->token)
	{
		ft_free_token(data->token);
		data->tokens_nb = 0;
		data->token = NULL;
	}
}
