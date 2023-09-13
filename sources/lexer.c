/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:01:25 by stakan            #+#    #+#             */
/*   Updated: 2023/09/13 14:01:25 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file lexer.c
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

int	lexer(t_base *base, char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (lexer_pipe(base, str, &i) == ERROR)
			break ;
		if (lexer_redir(base, str, &i) == ERROR)
			break ;
		if (lexer_text(base, str, &i) == ERROR)
			break ;
		if (lexer_quote(base, str, &i) == ERROR)
			break ;
		while (str[i] && ft_strchr(WHITESPACES, str[i]))
			i++;
	}
	if (str[i] != '\0')
	{
		exit_status(ENOMEM, 0);
		return (ERROR);
	}
	debug_print_str(base, "DEBUG", "print");
	return (1);
}
