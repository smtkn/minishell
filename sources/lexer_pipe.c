/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:01:05 by stakan            #+#    #+#             */
/*   Updated: 2023/09/13 14:01:06 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file lexer_pipe.c
 * @author Ahmet KARACA (akaraca)
 * @author Gorkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../includes/minishell.h"

int	lexer_pipe(t_base *base, char *str, int *i)
{
	char	*token;
	t_lexer	*new;

	if (str[*i] == '|' && str[*i + 1] != '|' && str[*i - 1] != '|')
	{
		token = ft_substr(str, *i, 1);
		if (!token)
			return (print_error(SHELLNAME, NULL, NULL, strerror(ENOMEM)));
		new = token_create(base, token, TOK_PIPE);
		if (!new)
		{
			free(token);
			return (print_error(SHELLNAME, NULL, NULL, strerror(ENOMEM)));
		}
		(*i)++;
	}
	return (0);
}
