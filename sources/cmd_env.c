/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:59:59 by stakan            #+#    #+#             */
/*   Updated: 2023/09/13 13:59:59 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file cmd_env.c
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

int	cmd_env(t_base *base, t_cmd *cmd, int i __attribute((unused)))
{
	t_env	*tmp;

	tmp = base->env;
	while (tmp != NULL)
	{
		if (tmp->data[1] != NULL)
		{
			ft_putstr_fd(tmp->data[0], cmd->outfile);
			write(cmd->outfile, "=", 1);
			ft_putstr_fd(tmp->data[1], cmd->outfile);
			write(cmd->outfile, "\n", 1);
		}
		else if (tmp->is_env_equal && tmp->data[1] == NULL)
		{
			ft_putstr_fd(tmp->data[0], cmd->outfile);
			write(cmd->outfile, "=\n", 2);
		}
		tmp = tmp->next;
	}
	exit_status(0, 0);
	return (0);
}
