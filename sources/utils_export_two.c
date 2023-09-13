/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:02:06 by stakan            #+#    #+#             */
/*   Updated: 2023/09/13 14:02:08 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file utils_export_two.c
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

int	export_left_arg_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '=')
	{
		if ((str[i] >= 97 && str[i] <= 122)
			|| (str[i] >= 65 && str[i] <= 90)
			|| str[i] == '_')
			i++;
		else
			return (1);
	}
	return (0);
}

int	export_arg_check(char **str)
{
	int	i;
	int	l;

	i = 1;
	while (str[i])
	{
		l = 0;
		while (str[i][l])
		{
			if (l == 0 && (str[i][l] == '=' || export_left_arg_check(str[i])))
			{
				print_error("export", str[i], NULL, "not a valid identifier");
				exit_status(1, 0);
				return (0);
			}
			l++;
		}
		i++;
	}
	return (1);
}
