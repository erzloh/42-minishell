/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:22:53 by alesspal          #+#    #+#             */
/*   Updated: 2023/04/11 14:23:09 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"
#include "../incl/tokenizer.h"

bool	check_unmatched_quotes(char *str)
{
	int	open_quote;

	open_quote = 0;
	while (str && *str)
	{
		if (!open_quote && (*str == '\'' || *str == '\"'))
			open_quote = *str;
		else if (*str == open_quote)
			open_quote = 0;
		str++;
	}
	if (open_quote)
	{
		ft_printf ("Error : quotes open\n");
		return (true);
	}
	return (false);
}

char	*ft_remove_quotes(char *str)
{
	char	*result;
	int		i;
	int		j;
	char	open_quote;

	if (!str)
		return (NULL);
	result = (char *)malloc(ft_strlen(str) + 1);
	if (!result)
		return (free(str), NULL);
	i = -1;
	j = 0;
	open_quote = 0;
	while (str[++i])
	{
		if ((str[i] == '"' || str[i] == '\'') && !open_quote)
			open_quote = str[i];
		else if (str[i] == open_quote)
			open_quote = 0;
		else
			result[j++] = str[i];
	}
	result[j] = '\0';
	free(str);
	return (result);
}

char *ft_strtrim_minishell(char *src) {
	int i, j;
	bool last_char_is_space;
	char current_quote = '\0';
	char *final_src;

	if (!src)
		return NULL;
	src = ft_strtrim(src, " \t\n\v\f\r");
	if (!src)
		return NULL;
	last_char_is_space = false;
	i = 0;
	j = 0;
	while (src[i]) {
		if (!current_quote && (src[i] == '\'' || src[i] == '\"'))
			current_quote = src[i];
		else if (current_quote && current_quote == src[i])
			current_quote = '\0';
		if (!last_char_is_space && ft_is_white_space(src[i]) && current_quote == '\0')
		{
			last_char_is_space = true;
		}
		else if (last_char_is_space && !ft_is_white_space(src[i]) && current_quote == '\0')
		{
			last_char_is_space = false;
		}
		else if (last_char_is_space && ft_is_white_space(src[i]) && current_quote == '\0')
		{
			j++;
		}
		i++;
	}
	final_src = ft_calloc(i - j + 1, sizeof(char));
	if (!final_src) {
		return NULL;
	}
	i = 0;
	j = 0;
	last_char_is_space = false;
	current_quote = '\0';
	while (src[i]) {
		if (!current_quote && (src[i] == '\'' || src[i] == '\"'))
			current_quote = src[i];
		else if (current_quote && current_quote == src[i])
			current_quote = '\0';
		if (!last_char_is_space && ft_is_white_space(src[i]) && current_quote == '\0')
		{
			last_char_is_space = true;
		}
		else if (last_char_is_space && !ft_is_white_space(src[i]) && current_quote == '\0')
		{
			last_char_is_space = false;
		}
		if ((last_char_is_space && !ft_is_white_space(src[i - 1])) || !ft_is_white_space(src[i]) || current_quote)
			final_src[j++] = src[i];
		i++;
	}
	final_src = ft_remove_quotes(final_src);
	return (final_src);
}

int	replace_env_var(char **input, int start, int end, char *env_var)
{
	int		env_var_len;
	int		input_len;
	int		new_len;
	char	*new_arg;
	char	*original_input;

	original_input = *input;
	env_var_len = ft_strlen(env_var);
	input_len = ft_strlen(*input);
	new_len = input_len - (end - start) + env_var_len;
	new_arg = malloc(sizeof(char) * (new_len + 1));
	if (!new_arg)
		return (-1);	// return -1 en cas d'erreur car -1 est pour relire partant du début
	new_arg = ft_memcpy(new_arg, *input, start - 1);
	new_arg[start - 1] = '\0';
	ft_strlcat(new_arg, env_var, new_len + 1);
	ft_strlcat(new_arg, *input + end, new_len + 1);
	free(original_input);
	*input = new_arg;
	return (start + env_var_len - 1);
}

char	*ft_get_env_name(char *arg, int *i, int env_start_ind)
{
	char	*env_name;

	if (!arg)
		return (NULL);
	if (arg[*i] != '?')
	{
		while (ft_isalnum(arg[*i]) || arg[*i] == '_' || arg[*i] == '-')
			(*i)++;
	}
	else
		(*i)++;
	env_name = ft_strndup(arg + env_start_ind, *i - env_start_ind);
	if (!env_name)
	{
		perror("ERROR : memory allocation failedkrkrkr");
		return (NULL);
	}
	return (env_name);
}

t_token	*ft_expend_cmd(t_token *token)
{
	int		i;
	int		env_start_ind;
	char	open_quote;
	char	*env_name;
	char	*env_value;
	t_token	*tail_token;

	tail_token = token;
	while (tail_token)
	{	
		if (check_unmatched_quotes(tail_token->arg))
			return (ft_free_token(token), NULL);
		open_quote = 0;
		i = 0;
		while (tail_token->arg && tail_token->arg[i])
		{
			if (!open_quote && (tail_token->arg[i] == '\'' || tail_token->arg[i] == '\"'))
				open_quote = tail_token->arg[i];
			else if (tail_token->arg[i] == open_quote)
				open_quote = 0;
			if (open_quote != '\'' && tail_token->arg[i] == '$')
			{
				i++;
				if (ft_isalnum(tail_token->arg[i]) || tail_token->arg[i] == '_' || tail_token->arg[i] == '-')
				{
					env_start_ind = i;
					env_name = ft_get_env_name(tail_token->arg, &i, env_start_ind);
					if (!env_name)
						return (NULL);
					env_value = ft_getenv(env_name);
					i = replace_env_var(&tail_token->arg, env_start_ind, i, env_value);
					if (i == -1)
						return (NULL);
					free(env_name);
				}
			}
			else
				i++;
		}
		tail_token->arg = ft_strtrim_minishell(tail_token->arg); // enleve tout les withespace
		tail_token = tail_token->next;
	}
	return (token);
}
