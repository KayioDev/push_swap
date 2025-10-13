/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:50:57 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/13 16:43:17 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}
