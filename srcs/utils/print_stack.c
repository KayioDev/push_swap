/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:42:43 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/01 22:07:46 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_stack(t_stack *stack)
{
	t_list	*cur;

	cur = stack->top;
	while (cur)
	{
		printf("%d\n", *(int *)cur->content);
		cur = cur->next;
	}
}
