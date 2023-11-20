/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_execve1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:18:45 by stakan            #+#    #+#             */
/*   Updated: 2023/11/20 13:18:47 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

char	**get_args(t_mparse *parse)
{
	char	**exec;
	int		i;
	int		j;

	j = 0;
	if (parse->text)
		while (parse->text[j])
			j++;
	exec = malloc(sizeof(char *) * (j + 2));
	if (!exec)
		return (NULL);
	i = 0;
	exec[0] = ft_strdup(parse->cmd);
	j = 1;
	if (parse->text)
	{
		while (parse->text[i])
		{
			exec[j] = ft_strdup(parse->text[i++]);
			j++;
		}
	}
	exec[j] = NULL;
	return (exec);
}
