/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:48:08 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/07 20:16:38 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(char **argv, t_stack *a, t_stack *b)
{
	t_list	*node;

	node = a->top;
	while (node)
	{
		if (node->content > node->next->content)
		{
			printf("KO");
			return ;
		}
		node = node->next;
	}
	if (b->top != NULL)
		printf("KO");
	else
		printf ("OK");
}