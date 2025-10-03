/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:50:57 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/03 03:19:49 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	*c1;
	int	*c2;
	int	tmp;

	if (!a || !a->top || !a->top->next)
		return ;
	c1 = a->top->content;
	c2 = a->top->next->content;
	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	*c1;
	int	*c2;
	int	tmp;

	if (!b || !b->top || !b->top->next)
		return ;
	c1 = b->top->content;
	c2 = b->top->next->content;
	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	*c1;
	int	*c2;
	int	tmp;

	if (a && a->top && a->top->next)
	{
		c1 = a->top->content;
		c2 = a->top->next->content;
		tmp = *c1;
		*c1 = *c2;
		*c2 = tmp;
	}
	if (b && b->top && b->top->next)
	{
		c1 = b->top->content;
		c2 = b->top->next->content;
		tmp = *c1;
		*c1 = *c2;
		*c2 = tmp;
	}
	write(1, "ss\n", 3);
}
