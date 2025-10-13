/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:09:02 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/13 16:39:24 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_order(t_stack *stack)
{
	t_list	*node;

	if (!stack || !stack->top)
		return (1);
	node = stack->top;
	while (node->next)
	{
		if (*(int *)node->content > *(int *)node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}
