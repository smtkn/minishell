/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:00:43 by stakan            #+#    #+#             */
/*   Updated: 2023/09/13 14:00:44 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file free.c
 * @author Görkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-10-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../includes/minishell.h"

void	free_env(t_env **env)
{
	t_env	*tmp;

	while (*env != NULL)
	{
		tmp = (*env)->next;
		free_pp_str((*env)->data);
		free(*env);
		(*env) = tmp;
	}
	*env = NULL;
}

void	free_lexer(t_lexer **lexer)
{
	t_lexer	*tmp;

	while (*lexer)
	{
		tmp = (*lexer)->next;
		free((*lexer)->str);
		free(*lexer);
		(*lexer) = tmp;
	}
	*lexer = NULL;
}

void	free_cmd(t_cmd **cmd)
{
	t_cmd	*tmp;

	while (*cmd)
	{
		tmp = (*cmd)->next;
		free_pp_str((*cmd)->full_cmd);
		free_pp_str((*cmd)->redirect);
		free(*cmd);
		(*cmd) = tmp;
	}
	*cmd = NULL;
}

void	free_all(t_base *base)
{
	ft_putendl_fd(RED"exit"END, STDERR_FILENO);
	rl_clear_history();
	free_cmd(&base->cmd);
	free_lexer(&base->lexer);
	free_env(&base->env);
	free(base->input_line);
}
