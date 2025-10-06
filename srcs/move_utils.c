/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 03:40:00 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/06 19:07:07 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_double_moves(t_stack *a, t_stack *b, t_cost *c)
{
	while (c->cost_a > 0 && c->cost_b > 0)
	{
		rr(a, b);
		c->cost_a--;
		c->cost_b--;
	}
	while (c->cost_a < 0 && c->cost_b < 0)
	{
		rrr(a, b);
		c->cost_a++;
		c->cost_b++;
	}
}

static void	exec_rotations(t_stack *stack, int *cost, void (*f)(t_stack *),
	void (*rev)(t_stack *))
{
	while (*cost > 0)
	{
		f(stack);
		(*cost)--;
	}
	while (*cost < 0)
	{
		rev(stack);
		(*cost)++;
	}
}

static void	exec_single_moves(t_stack *a, t_stack *b, t_cost *c)
{
	exec_rotations(a, &c->cost_a, ra, rra);
	exec_rotations(b, &c->cost_b, rb, rrb);
}

void	do_cheapest_move(t_stack *a, t_stack *b, t_cost c)
{
	exec_double_moves(a, b, &c);
	exec_single_moves(a, b, &c);
	pb(a, b);
}

void	do_cheapest_move_to_a(t_stack *a, t_stack *b, t_cost c)
{
	exec_double_moves(a, b, &c);
	exec_single_moves(a, b, &c);
	pa(a, b);
}
