/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:25:30 by stakan            #+#    #+#             */
/*   Updated: 2023/11/20 13:25:32 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (0);
	ptr -> next = NULL;
	ptr -> content = content;
	return (ptr);
}
