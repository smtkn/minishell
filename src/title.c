/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:19:02 by stakan            #+#    #+#             */
/*   Updated: 2023/11/20 13:19:04 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	*prepare_title(void)
{
	char	*path;
	char	*title;

	path = malloc(256);
	if (!path)
		return (NULL);
	if (getcwd(path, 256) == NULL)
	{
		free(path);
		return (NULL);
	}
	title = create_title(path);
	free(path);
	return (title);
}

char	*create_username(char *path)
{
	char	*lastslash;
	char	*username;

	lastslash = strrchr(path, '/');
	username = NULL;
	if (lastslash)
	{
		lastslash++;
		username = malloc(strlen(lastslash) + 1);
		if (!username)
			return (NULL);
		strcpy(username, lastslash);
	}
	return (username);
}

char	*create_title(char *path)
{
	char	*username;
	char	*result;

	if (!path || strcmp(path, "/") == 0)
		return (strdup("/"));
	username = create_username(path);
	if (!username)
		return (NULL);
	if (strcmp(username, C_NAME) == 0 && strcmp(path, "/Users/" C_NAME) == 0)
		result = strdup("~");
	else
		result = strdup(username);
	free(username);
	return (result);
}

char	*finish_title(void)
{
	char	*path;
	char	*npath;
	char	*last;

	path = prepare_title();
	npath = ft_strjoin(T_NAME, path);
	last = ft_strjoin(npath, " $ ");
	free(path);
	free(npath);
	return (last);
}
