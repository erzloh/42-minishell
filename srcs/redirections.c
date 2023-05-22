/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 08:59:43 by eholzer           #+#    #+#             */
/*   Updated: 2023/05/22 16:39:25 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_redirect_fd_in_token(t_token *token)
{
	while (token)
	{
		if (token->redirect.r_in_type == INPUT_REDIRECT)
			set_input_redirect(token);
		else if (token->redirect.r_in_type == HEREDOC_REDIRECT)
			set_heredoc_redirect(token);
		if (token->redirect.r_out_type == OUTPUT_REDIRECT)
			set_output_redirect(token);
		else if (token->redirect.r_out_type == APPEND_REDIRECT)
			set_append_redirect(token);
		token = token->next;
	}
}

void	set_input_redirect(t_token *token)
{
	token->redirect.infile_fd = open(token->redirect.infile, O_RDONLY);
	if (token->redirect.infile_fd < 0)
		token->redirect.is_valid_infile = 0;
}

static void	set_heredoc_pipe(int **heredoc_pipe)
{
	*heredoc_pipe = malloc(sizeof(int) * 2);
	if (!*heredoc_pipe)
		fatal_error("Error when trying to malloc() heredoc_pipe");
	if (pipe(*heredoc_pipe) < 0)
		fatal_error("Error when trying to pipe() heredoc_pipe");
}

void	set_heredoc_redirect(t_token *token)
{
	int		*heredoc_pipe;
	char	*heredoc_input;
	char	*eof;

	eof = token->redirect.infile;
	set_heredoc_pipe(&heredoc_pipe);
	heredoc_input = readline("> ");
	if (heredoc_input)
	{
		while (heredoc_input
			&& ft_strncmp(heredoc_input, eof, ft_strlen(eof)) != 0)
		{
			write(heredoc_pipe[1], heredoc_input, ft_strlen(heredoc_input));
			write(heredoc_pipe[1], "\n", 1);
			free(heredoc_input);
			heredoc_input = readline("> ");
		}
	}
	if (heredoc_input)
		free(heredoc_input);
	token->redirect.infile_fd = heredoc_pipe[0];
	token->redirect.heredoc_pipe = heredoc_pipe;
}

void	set_output_redirect(t_token *token)
{
	char	*outfile;
	int		outfile_fd;

	outfile = token->redirect.outfile;
	outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd < 0)
		fatal_error("Error when openning an outfile");
	token->redirect.outfile_fd = outfile_fd;
}
