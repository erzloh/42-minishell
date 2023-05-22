/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:38:20 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/22 17:21:24 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/get_next_line.h"
#include "../../std/incl/std.h"

char	*ft_read_file(int fd)
{
	char	*temp;
	char	*line;
	char	*file;

	file = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = ft_strjoin(file, line);
		if (file)
			free(file);
		file = temp;
		if (!file)
		{
			if (line)
				free(line);
			return (NULL);
		}
		if (line)
			free(line);
	}
	return (file);
}
