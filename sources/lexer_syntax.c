/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:01:17 by stakan            #+#    #+#             */
/*   Updated: 2023/09/13 14:01:19 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file lexer_syntax.c
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

int	lexer_syntax(t_lexer *lexer)
{
	while (lexer)
	{
		if (lexer->flag == TOK_REDIR || lexer->flag == TOK_HEREDOC)
		{
			if (lexer->next == NULL || !(lexer->next->flag
					& (TOK_TEXT | TOK_D_QUOTE | TOK_S_QUOTE | TOK_REDIR_FILE))
				|| lexer->next->flag & (TOK_REDIR | TOK_HEREDOC))
				return (print_error(SHELLNAME, ERR_SYNTAX, NULL, ERR_REDIR));
		}
		if (lexer->flag == TOK_PIPE)
			if (lexer->next == NULL || !(lexer->next->flag
					& (TOK_TEXT | TOK_D_QUOTE | TOK_S_QUOTE))
				|| lexer->prev == NULL)
				return (print_error(SHELLNAME, ERR_SYNTAX, NULL, ERR_PIPE));
		lexer = lexer->next;
	}
	return (0);
}
