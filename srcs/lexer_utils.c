/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:06:33 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/15 17:17:34 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/lexer_utils.h"

int	ft_is_pipe_or_redirec(int c)
{
	return (c == '|' || c == '<' || c == '>');
}

void	update_word_count(const char *str, int i, int *nb_word)
{
	if ((i > 0 && ft_is_white_space(str[i]) && !ft_is_white_space(str[i - 1])
			&& !ft_is_pipe_or_redirec(str[i - 1]))
		|| ft_is_pipe_or_redirec(str[i]))
	{
		(*nb_word)++;
		if (i > 0 && ft_is_pipe_or_redirec(str[i])
			&& !ft_is_pipe_or_redirec(str[i - 1])
			&& !ft_is_white_space(str[i - 1]))
			(*nb_word)++;
	}
}

/* int main()
{
	char *cmd = ft_strdup("     salut \" a \'a\'  \"  a \'  \"   \'a f\' afaf a f\"aa   a\"\'   a  ");

	printf("cmd = %s\n", cmd);
	printf("nb of word = %i\n", ft_count_arg(cmd));
	free(cmd);

	cmd = ft_strdup("     salut \" a \'a\' | \" | a \' >output.txt \"   \'a f\' afaf a f\"aa   a\"\'   a  > output.txt");

	printf("cmd = %s\n", cmd);
	printf("nb of word = %i\n", ft_count_arg(cmd));
	free(cmd);
	cmd = ft_strdup("|     salut \" a \'a\' | \"|a \' >output.txt \"   \'a f\' afaf a f\"aa   a\"\'   a>output.txt|");

	printf("cmd = %s\n", cmd);
	printf("nb of word = %i\n", ft_count_arg(cmd));
	free(cmd);
	return (0);
} */

char	*create_word_and_update_start(const char *str, int i, int *start)
{
	int		length;
	char	*word;

	length = i - *start;
	if (length > 0)
	{
		word = ft_strndup(str + *start, length);
		if (!word)
			ft_fatal_error("memory allocation error\n", E_ERROR_MALLOC);
		*start = i;
	}
	else
	{
		word = ft_strndup(str + *start, 1);
		if (!word)
			ft_fatal_error("memory allocation error\n", E_ERROR_MALLOC);
		*start = i + 1;
	}
	return (word);
}

char	*handle_character(const char *str, int i, int *start)
{
	if (ft_is_pipe_or_redirec(str[i]) || ft_is_white_space(str[i]))
		return (create_word_and_update_start(str, i, start));
	else
		return (NULL);
}

/* int main()
{
	int	i = 0;
	char *cmd = ft_strdup("     salut \" a \'a\'  \"  a \'  \"   \'a f\' afaf a f\"aa   a\"\'   a  ");
	char *arg = ft_get_arg(cmd, &i);

	printf("cmd = %s\n", cmd);
	printf("word = %s && i = %i\n", arg, i);
	free(cmd);
	free(arg);

	cmd = ft_strdup("     salut \" a \'a\' | \" | a \' >output.txt \"   \'a f\' afaf a f\"aa   a\"\'   a  > output.txt");
	arg = ft_get_arg(cmd, &i);
	printf("cmd = %s\n", cmd);
	printf("word = %s && i = %i\n", arg, i);
	free(cmd);
	free(arg);

	cmd = ft_strdup("     salut \" a \'a\' | \"|a \' >output.txt \"   \'a f\' afaf a f\"aa   a\"\'   a>output.txt");
	arg = ft_get_arg(cmd, &i);
	printf("cmd = %s\n", cmd);
	printf("word = %s && i = %i\n", arg, i);
	free(cmd);
	free(arg);
	return (0);
} */

/* int	main()
{
	int		i = 0;
	int		j = -1;
	int		nb_word;
	char	*cmd;
	char	**split;

	cmd = ft_strdup("     salut \" a \'a\'  \"  a \'  \"   \'a f\' afaf a f\"aa   a\"\'   a  ");
	printf("cmd = %s\n", cmd);
	nb_word = ft_count_arg(cmd);
	printf("nb_word = %i\n", nb_word);
	split = ft_lexer(cmd);
	printf("lexer = {");
	while (++j < nb_word)
	{
		printf("%s", split[j]);
		if (j < nb_word - 1)
			printf(", ");
	}
	printf("}\n");
	free(cmd);
	ft_free_2d_char(split);

	printf("------------------------------------------------------------------------------------------------------------------------\n");

	cmd = ft_strdup("     salut \" a \'a\' | \" | a \' >output.txt \"   \'a f\' afaf a f\"aa   a\"\'   a  > output.txt");
	printf("cmd = %s\n", cmd);
	nb_word = ft_count_arg(cmd);
	printf("nb_word = %i\n", nb_word);
	split = ft_lexer(cmd);
	printf("lexer = {");
	j = -1;
	while (++j < nb_word)
	{
		printf("%s", split[j]);
		if (j < nb_word - 1)
			printf(", ");
	}
	printf("}\n");
	free(cmd);
	ft_free_2d_char(split);

	printf("------------------------------------------------------------------------------------------------------------------------\n");
	
	cmd = ft_strdup("|     salut \" a \'a\' | \"|a \' >output.txt \"   \'a f\' afaf a f\"aa   a\"\'   a>output.txt|");
	printf("cmd = %s\n", cmd);
	nb_word = ft_count_arg(cmd);
	printf("nb_word = %i\n", nb_word);
	split = ft_lexer(cmd);
	printf("lexer = {");
	j = -1;
	while (++j < nb_word)
	{
		printf("%s", split[j]);
		if (j < nb_word - 1)
			printf(", ");
	}
	printf("}\n");
	free(cmd);
	ft_free_2d_char(split);
	return (0);
} */
