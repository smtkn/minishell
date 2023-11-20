/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:16:42 by stakan            #+#    #+#             */
/*   Updated: 2023/11/20 13:16:44 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int	print_error(void)
{
	printf("%s\n", "minishell: syntax error near unexpected token");
	return (0);
}

int	is_space(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] && cmd[i] == ' ')
		i++;
	if (!cmd[i])
		return (0);
	return (1);
}
