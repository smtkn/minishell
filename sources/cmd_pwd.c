/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:00:08 by stakan            #+#    #+#             */
/*   Updated: 2023/09/13 14:00:08 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file cmd_pwd.c
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

int	cmd_pwd(t_base *base __attribute((unused)),
	t_cmd *cmd, int i __attribute((unused)))
{
	char	pwd[256];

	getcwd(pwd, sizeof(pwd));
	ft_putendl_fd(pwd, cmd->outfile);
	return (0);
}
