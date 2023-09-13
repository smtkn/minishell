/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:00:18 by stakan            #+#    #+#             */
/*   Updated: 2023/09/13 14:00:18 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file cmd_unset.c
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

int	cmd_unset(t_base *base, t_cmd *cmd, int i __attribute((unused)))
{
	t_env	*tmp;
	t_env	*before;
	t_env	*del;

	while (cmd->full_cmd[++i] != NULL)
	{
		tmp = base->env;
		tmp->prev = NULL;
		while (tmp != NULL)
		{
			if (ft_strcmp_edited(tmp->data[0], cmd->full_cmd[i]) == 0)
			{
				del = tmp;
				tmp->prev->next = tmp->next;
				free_pp_str(del->data);
				free(del);
				break ;
			}
			before = tmp;
			tmp = tmp->next;
			if (tmp != NULL)
				tmp->prev = before;
		}
	}
	return (0);
}
