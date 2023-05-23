/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_arr_cat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:37:55 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/23 13:15:32 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/std.h"

char	**ft_str_arr_cat(char **str_arr, const char *new_str)
{
	int		i;
	int		len_str_arr;
	char	**new_str_arr;

	if (!new_str)
		return (str_arr);
	len_str_arr = ft_str_arr_len(str_arr);
	new_str_arr = malloc((len_str_arr + 2) * sizeof(char *));
	if (!new_str_arr)
		ft_fatal_error("memory allocation error\n", E_ERROR_MALLOC);
	i = -1;
	while (++i < len_str_arr)
	{
		new_str_arr[i] = ft_strdup(str_arr[i]);
		if (!new_str_arr[i])
			ft_fatal_error("memory allocation error\n", E_ERROR_MALLOC);
	}
	new_str_arr[len_str_arr] = ft_strdup(new_str);
	if (!new_str_arr[len_str_arr])
		ft_fatal_error("memory allocation error\n", E_ERROR_MALLOC);
	new_str_arr[len_str_arr + 1] = NULL;
	ft_free_2d_char(str_arr);
	return (new_str_arr);
}

/* int	main(int argc, char **argv)
{
	int		i;
	char	**argv_cat = NULL;

	if (argc <= 1)
		return (1);
	char **argv_cpy = ft_str_arrdup(argv);
	printf("HERE\n");
	i = -1;
	while (argv_cpy[++i])
	{
		printf("argv_cpy[%i] = %s\n", i, argv_cpy[i]);
	}
	printf("HERE\n");
	i = -1;
	while (argv_cpy[++i])
		argv_cat = ft_str_arr_cat(argv_cat, argv_cpy[i]);
	printf("HERE\n");
	i = -1;
	while (argv_cat[++i])
		printf("argv_cat[%i] = %s\n", i, argv_cat[i]);
	return (0);
} */
