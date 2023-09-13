/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:00:30 by stakan            #+#    #+#             */
/*   Updated: 2023/09/13 14:00:31 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file debugging.c
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

/**
 * @brief Printing all cmd linked list.
 * NOTE: Eger export'la DEFINE=print define etmisse yazdirir.
 * 
 * @param base 
 * @param env_var 
 * @param value 
 */
void	debug_print_cmd(t_base *base, char *env_var, char *value)
{
	t_cmd	*write;
	int		i;
	int		l;

	if (env_is_have(base, env_var, value))
	{
		write = base->cmd;
		while (write)
		{
			i = -1;
			while (write->full_cmd[++i])
				printf("CMD->[%d]: %s\n", i, write->full_cmd[i]);
			l = 0;
			while (write->redirect && write->redirect[l])
			{
				printf("CMD_RED->[%d]: %s\n", l, write->redirect[l]);
				l++;
			}
			printf("[%d]: in: %d out: %d\n", i, write->infile, write->outfile);
			write = write->next;
		}
		printf("##########################################################\n");
	}
}

/**
 * @brief Printing Lexer's all linked list.
 * NOTE: Eger export'la DEFINE=print define etmisse yazdirir.
 * 
 * @param base 
 * @param env_var 
 * @param value 
 */
void	debug_print_str(t_base *base, char *env_var, char *value)
{
	t_lexer	*tmp;

	tmp = base->lexer;
	if (env_is_have(base, env_var, value))
	{
		while (tmp)
		{
			printf("			->: STR: %s FLAG: %d\n", tmp->str, tmp->flag);
			tmp = tmp->next;
		}
		printf("##########################################################\n");
	}
}
