/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_env_expand_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:00:56 by stakan            #+#    #+#             */
/*   Updated: 2023/09/13 14:00:57 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_it_expand(t_base *base, int status)
{
	t_lexer	*last;

	last = lexer_lstlast(base->lexer);
	if (last && last->flag & status)
		return (1);
	return (0);
}

char	*env_expand_seperate_third(t_base *base, char *env_name)
{
	char	*str;

	if (is_it_expand(base, TOK_HEREDOC))
	{
		str = ft_strjoin("$", env_name);
		return (str);
	}
	else
		str = env_findret(base, env_name);
	if (!str)
	{
		free(str);
		if (is_it_expand(base, (TOK_REDIR | TOK_HEREDOC)))
			str = ft_strjoin("$", env_name);
		else
			str = ft_strdup("");
		return (str);
	}
	return (str);
}

char	*env_expand_next_next(t_base *base, char *token, int *i, char *new)
{
	int		l;
	char	*env_name;
	char	*str;

	l = (*i);
	while (token[*i] && token[*i] != '$' && !ft_strchr(WHITESPACES, token[*i]))
		(*i)++;
	env_name = ft_substr(token, l, *i - l);
	str = env_expand_seperate_third(base, env_name);
	free(env_name);
	if (new != NULL && str != NULL)
	{
		base->mem_1 = ft_strjoin(new, str);
		free(new);
		free(str);
		return (base->mem_1);
	}
	if (new == NULL && str != NULL)
		return (str);
	return (new);
}
