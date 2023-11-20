/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:18:33 by stakan            #+#    #+#             */
/*   Updated: 2023/11/20 13:18:35 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

void	change_old(char *str, t_shell *m_shell)
{
	t_list	*tmp;
	t_env	*env;

	tmp = m_shell->env;
	while (tmp)
	{
		env = tmp->content;
		if (!ft_strcmp(env->key, "OLDPWD"))
		{
			if (env->value)
				free(env->value);
			env->value = str;
		}
		tmp = tmp->next;
	}
}

void	dont_change_oldpwd(char *str, t_shell *m_shell)
{
	t_list	*tmp;
	t_env	*env;
	char	*oldpwd;

	(void)str;
	oldpwd = NULL;
	tmp = m_shell->env;
	while (tmp)
	{
		env = tmp->content;
		if (!ft_strcmp(env->key, "OLDPWD"))
		{
			oldpwd = ft_strdup(env->value);
			break ;
		}
		tmp = tmp->next;
	}
	if (oldpwd)
		oldpwd_(oldpwd, m_shell);
	else
		free(oldpwd);
}

void	change_pwd(t_mparse	*data, t_shell *m_shell)
{
	t_list	*tmp;
	t_env	*env;
	char	cwd[1024];

	tmp = m_shell->env;
	while (tmp)
	{
		env = tmp->content;
		if (!ft_strcmp(env->key, "PWD")
			&& data->text && !ft_strcmp(data->text[0], "~"))
		{
			if (env->value)
				free(env->value);
			env->value = get_home(m_shell);
		}
		else if (!ft_strcmp(env->key, "PWD")
			&& data->text && !ft_strcmp(data->text[0], ".."))
		{
			if (env->value)
				free(env->value);
			env->value = ft_strdup(getcwd(cwd, sizeof(cwd)));
		}
		_change_pwd(&env);
		tmp = tmp->next;
	}
}
