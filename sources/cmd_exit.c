/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:00:04 by stakan            #+#    #+#             */
/*   Updated: 2023/09/13 14:00:04 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file cmd_exit.c
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

/**
 * @brief Get the lexer count object
 * 
 * @param base 
 * @return int 
 */
static int	get_lexer_count(t_base *base)
{
	t_lexer	*tmp;
	int		count;

	tmp = base->lexer;
	count = 0;
	while (tmp->str != NULL)
	{
		count++;
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	return (count);
}

static bool	err_num_is_num(char *argv)
{
	int	i;

	i = 0;
	if (argv == NULL || argv[0] == '\0')
	{
		print_error(SHELLNAME, "exit", argv, "numeric argument required");
		return (false);
	}
	else if ((argv[0] == '-' || argv[0] == '+') && argv[1] != '\0')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
		{
			print_error(SHELLNAME, "exit", argv, "numeric argument required");
			return (false);
		}
		i++;
	}
	return (true);
}

int	cmd_exit(t_base *base __attribute((unused)),
	t_cmd *cmd, int i __attribute((unused)))
{
	int	argc;

	ft_putendl_fd(RED"exit"END, STDERR_FILENO);
	argc = get_lexer_count(base);
	if (argc >= 2 && err_num_is_num(cmd->full_cmd[1]) == false)
		exit_status(255, 0);
	else if (argc == 2)
		exit_status(ft_atoi(cmd->full_cmd[1]), 0);
	else if (argc > 2)
	{
		print_error(SHELLNAME, "exit", NULL, "to many arguments");
		exit_status(1, 0);
		return (EXIT_FAILURE);
	}
	exit(exit_status(0, 1));
}
