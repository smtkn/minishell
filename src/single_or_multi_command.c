/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_or_multi_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:18:57 by stakan            #+#    #+#             */
/*   Updated: 2023/11/20 13:18:58 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	single_or_multi_command(t_shell *m_shell)
{
	t_mparse	*parse;
	int			i;

	i = 0;
	parse = m_shell->mparse;
	while (parse)
	{
		if (parse->type == 2)
			i++;
		parse = parse->next;
	}
	return (i);
}
