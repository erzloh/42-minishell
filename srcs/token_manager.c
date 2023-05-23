/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:33:34 by alesspal          #+#    #+#             */
/*   Updated: 2023/05/23 16:23:51 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/tokenizer.h"

void	ft_formatting_redirect(t_redirect *red, char **input, int *i)
{
	if (input[*i][0] == '<')
	{
		if (input[++(*i)][0] == '<')
		{
			(*red).infile = ft_strdup(input[++(*i)]);
			(*red).r_in_type = HEREDOC_REDIRECT;
			return ;
		}
		(*red).infile = ft_strdup(input[*i]);
		(*red).r_in_type = INPUT_REDIRECT;
	}
	else if (input[*i][0] == '>')
	{
		if (input[++(*i)][0] == '>')
		{
			(*red).outfile = ft_strdup(input[++(*i)]);
			(*red).r_out_type = APPEND_REDIRECT;
			return ;
		}
		(*red).outfile = ft_strdup(input[*i]);
		(*red).r_out_type = OUTPUT_REDIRECT;
	}
}

int	ft_create_token(t_token **token, char **formatted_input)
{
	int		i;
	int		nb_token;
	t_token	*tail_token;

	nb_token = 1;
	*token = ft_init_token(nb_token);
	tail_token = *token;
	i = -1;
	while (formatted_input[++i])
	{
		if (formatted_input[i][0] == '|')
		{
			nb_token++;
			tail_token->next = ft_init_token(nb_token);
			tail_token = tail_token->next;
		}
		else if (formatted_input[i][0] == '<' || formatted_input[i][0] == '>')
			ft_formatting_redirect(&tail_token->redirect, formatted_input, &i);
		else
			tail_token->cmd_arr = ft_str_arr_cat(tail_token->cmd_arr,
					formatted_input[i]);
	}
	return (nb_token);
}

t_token	*ft_init_token(int id)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		ft_fatal_error("memory allocation error", E_ERROR_MALLOC);
	new_token->id = id;
	new_token->cmd_arr = NULL;
	new_token->is_valid_cmd = false;
	new_token->is_builtin = false;
	new_token->redirect.infile = NULL;
	new_token->redirect.infile_fd = STDIN_FILENO;
	new_token->redirect.r_in_type = NO_R_IN;
	new_token->redirect.is_valid_infile = true;
	new_token->redirect.outfile = NULL;
	new_token->redirect.outfile_fd = STDOUT_FILENO;
	new_token->redirect.r_out_type = NO_R_OUT;
	new_token->redirect.heredoc_pipe = NULL;
	new_token->pid = -1;
	new_token->next = NULL;
	return (new_token);
}

void	ft_free_token(t_token *token)
{
	t_token	*next;

	while (token)
	{
		next = token->next;
		if (token->cmd_arr)
			ft_free_2d_char(token->cmd_arr);
		if (token->redirect.infile)
			free(token->redirect.infile);
		if (token->redirect.outfile)
			free(token->redirect.outfile);
		if (token->redirect.heredoc_pipe)
			free(token->redirect.heredoc_pipe);
		free(token);
		token = next;
	}
}

void	ft_display_token(t_token *token)
{
	int	i;

	while (token)
	{
		ft_printf("token id %i :\n", token->id);
		if (token->cmd_arr)
		{
			i = -1;
			while (token->cmd_arr[++i])
				printf("cmd_arr[%i] = %s\n", i, token->cmd_arr[i]);
		}
		printf("cmd_isvalid = %i\n", token->is_valid_cmd);
		printf("is_builtin = %i\n", token->is_builtin);
		if (token->redirect.infile)
			ft_printf("infile_str = %s\n", token->redirect.infile);
		ft_printf("infile_fd = %i\n", token->redirect.infile_fd);
		ft_printf("infile enum = %i\n", token->redirect.r_in_type);
		if (token->redirect.outfile)
			ft_printf("outfile_str = %s\n", token->redirect.outfile);
		ft_printf("outfile_fd = %i\n", token->redirect.outfile_fd);
		ft_printf("outfile enum = %i\n", token->redirect.r_out_type);
		ft_printf("pid = %i\n", token->pid);
		token = token->next;
	}
}
