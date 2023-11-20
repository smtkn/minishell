/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:16:53 by stakan            #+#    #+#             */
/*   Updated: 2023/11/20 13:16:58 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	killer(int sig)
{
	(void)sig;
	g_does_have_heredoc = -3;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_replace_line("", 0);
	rl_on_new_line();
}

void	set_heredoc(int sig)
{
	(void)sig;
	g_does_have_heredoc = -10;
}
