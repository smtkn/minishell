/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_free2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:15:33 by stakan            #+#    #+#             */
/*   Updated: 2023/11/20 13:15:35 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	free_text(char **text)
{
	int	i;

	i = 0;
	if (text)
	{
		if (text[i])
		{
			while (text[i])
				free(text[i++]);
		}
		free(text);
	}
}

void	_free_parse(t_mparse *mparse)
{
	t_mparse	*tmp;

	while (mparse)
	{
		tmp = mparse;
		mparse = mparse->next;
		if (tmp->cmd)
			free(tmp->cmd);
		if (tmp->text)
			free_text(tmp->text);
		free(tmp);
	}
}

void	free_parser(t_shell *m_shell)
{
	t_mparse	*parse;

	parse = m_shell->mparse;
	if (parse)
	{
		_free_parse(parse);
	}
	else if (m_shell->mparse)
	{
		free(m_shell->mparse);
	}
}

int	*create_pipe(void)
{
	int	index;
	int	*fd;

	fd = (int *)malloc(sizeof(int) * 6);
	if (!fd)
		return (NULL);
	index = -1;
	while (++index < 6)
		fd[index] = 0;
	return (fd);
}
