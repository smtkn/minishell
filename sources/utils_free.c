/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:02:31 by stakan            #+#    #+#             */
/*   Updated: 2023/09/13 14:02:33 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file utils_free.c
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

void	free_fork_inits(t_base *base, int **fd)
{
	int	i;

	if (base->cmd_count > 1)
	{
		i = 0;
		while (i < base->cmd_count)
		{
			free(fd[i]);
			i++;
		}
		free(fd);
		free(base->pid);
	}
}

void	free_pp_str(char **line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		free(line[i++]);
	}
	if (line != NULL)
		free(line);
}
