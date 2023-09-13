/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:47:06 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/13 08:47:06 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	minishell_part_2(t_base *base)
{
	if (lexer(base, base->input_line) != ERROR)
	{
		if (lexer_syntax(base->lexer) == ERROR)
			exit_status(2, 0);
		else
		{
			cmd(base);
			close_cmd_fd(base->cmd);
			free_fork_inits(base, base->fd);
			free_cmd(&base->cmd);
		}
		free_lexer(&base->lexer);
	}
	free(base->input_line);
}

void	minishell(t_base *base)
{
	char	*title;

	signal(SIGQUIT, SIG_IGN);
	commands_init(base);
	title = malloc(256);
	while (1)
	{
		signal(SIGINT, action);
		termios_change(false);
		free(title);
		title = finish_title();
		base->input_line = readline(title);
		if (!base->input_line)
		{
			termios_change(true);
			break ;
		}
		if (history_empty_check(base->input_line))
			add_history(base->input_line);
		minishell_part_2(base);
	}
	free_all(base);
}
