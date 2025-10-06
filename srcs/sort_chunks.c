/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 04:45:00 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/06 19:13:41 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_push_logic(t_stack *a, t_stack *b, int *limit,
	int *pushed, int chunk)
{
	int	val;

	val = *(int *)a->top->content;
	if (val < *limit)
	{
		pb(a, b);
		(*pushed)++;
		if (*(int *)b->top->content < *limit - (chunk / 2))
			rb(b);
	}
	else
		ra(a);
}

void	push_chunks(t_stack *a, t_stack *b)
{
	int	total;
	int	chunk;
	int	limit;
	int	pushed;

	total = a->size;
	chunk = total / 4;
	limit = chunk;
	pushed = 0;
	while (a->size > 3)
	{
		handle_push_logic(a, b, &limit, &pushed, chunk);
		if (pushed >= chunk)
		{
			limit += chunk;
			pushed = 0;
		}
		if (limit >= total)
			limit = total + 1;
	}
}

void	cheapest_sort(t_stack *a, t_stack *b)
{
	t_cost	c;

	push_chunks(a, b);
	sort_three(a);
	while (b->size > 0)
	{
		c = find_cheapest_to_push_to_a(a, b);
		do_cheapest_move_to_a(a, b, c);
	}
	bring_min_on_top(a);
}
