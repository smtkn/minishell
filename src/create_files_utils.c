/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_files_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:15:09 by stakan            #+#    #+#             */
/*   Updated: 2023/11/20 13:15:12 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	create_in_files_me(t_mparse *mparse)
{
	t_mparse	*nparse;
	char		str[256];
	char		*pwd;
	char		*tmp;

	nparse = mparse->next;
	getcwd(str, 256);
	tmp = ft_strjoin(str, "/");
	pwd = ft_strjoin(tmp, nparse->text[0]);
	if (tmp)
		free(tmp);
	if (!access(pwd, F_OK))
		nparse->fd = open(pwd, O_RDONLY, 0777);
	else
	{
		if (pwd)
			free(pwd);
		printf("minishell: %s: No such file or directory\n", mparse->text[0]);
		return (0);
	}
	if (pwd)
		free(pwd);
	mparse->infile = nparse->fd;
	return (1);
}
