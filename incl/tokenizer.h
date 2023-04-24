/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:55:13 by alesspal          #+#    #+#             */
/*   Updated: 2023/04/24 09:22:52 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TOKENIZER_H
# define TOKENIZER_H
# include "../libft/libft.h"

typedef struct s_token
{
	char			*cmd;
	char			*arg;
	char			*flag;
	struct s_token	*next;
	int				cmds_nb;
	int				pipes_nb;
}	t_token;

t_token	*create_token(void);
void	ft_free_token(t_token *token);
void	ft_display_token(t_token *token);

// laxer
t_token		*ft_laxing_cmd(char *input);
int			ft_is_pipe_or_red(int c);
char		*ft_get_cmd(char *input, int *index);
char		*ft_get_arg(char *input, int *index);
char		*ft_get_flag(char *input, int *index);

// checkers
char		*ft_find_and_check_echo_arg(char *arg, int *index);
char		*ft_find_and_check_cd_arg(char *input, int *index);
bool		check_unmatched_quotes(char *str);

// expender
t_token		*ft_expend_cmd(t_token *token);
char		*ft_remove_quotes(char *str);
char		*ft_strtrim_minishell(char *src);

#endif