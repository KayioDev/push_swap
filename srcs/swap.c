/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:50:57 by klima-do          #+#    #+#             */
/*   Updated: 2025/09/30 20:50:11 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	t_list	*n1;
	t_list	*n2;

	if (!stack_a->top || !stack_a->top->next)
		return ;
	n1 = stack_a->top;
	n2 = n1->next;
	n1->next = n2->next;
	n2->next = n1;
	stack_a->top = n2;
}

void	sb(t_stack *stack_b)
{
	t_list	*n1;
	t_list	*n2;

	if (!stack_b->top || !stack_b->top->next)
		return ;
	n1 = stack_b->top;
	n2 = n1->next;
	n1->next = n2->next;
	n2->next = n1;
	stack_b->top = n2;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}