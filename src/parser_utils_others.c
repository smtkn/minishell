/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_others.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:17:50 by stakan            #+#    #+#             */
/*   Updated: 2023/11/20 13:17:52 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	free_parse(t_mparse *parse)
{
	if (!parse)
		return ;
	free(parse->cmd);
	free_text(parse->text);
	free(parse);
}
