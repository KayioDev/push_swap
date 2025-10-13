/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:10:00 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/10 17:10:19 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_total_cost(int a, int b)
{
	if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
	{
		if (ft_abs(a) > ft_abs(b))
			return (ft_abs(a));
		return (ft_abs(b));
	}
	return (ft_abs(a) + ft_abs(b));
}

t_cost	calculate_cost(t_stack *a, t_stack *b, t_list *n, int i)
{
	t_cost	c;
	int		target;

	c.node = n;
	if (i <= a->size / 2)
		c.cost_a = i;
	else
		c.cost_a = -(a->size - i);
	target = find_target_pos_in_b(b, *(int *)n->content);
	if (target <= b->size / 2)
		c.cost_b = target;
	else
		c.cost_b = -(b->size - target);
	c.total = calc_total_cost(c.cost_a, c.cost_b);
	return (c);
}

//   7 6 5 4 3  2  1 0 //

t_cost	find_cheapest(t_stack *a, t_stack *b)
{
	t_list	*n;
	t_cost	best;
	t_cost	curr;
	int		i;

	n = a->top;
	best.total = 2147483647;
	i = 0;
	while (n)
	{
		curr = calculate_cost(a, b, n, i++);
		if (curr.total < best.total
			|| (curr.total == best.total
				&& ft_abs(curr.cost_a) + ft_abs(curr.cost_b)
				< ft_abs(best.cost_a) + ft_abs(best.cost_b)))
			best = curr;
		n = n->next;
	}
	return (best);
}

t_cost	calculate_cost_to_a(t_stack *a, t_stack *b, t_list *n, int i_b)
{
	t_cost	c;
	int		target;

	c.node = n;
	if (i_b <= b->size / 2)
		c.cost_b = i_b;
	else
		c.cost_b = -(b->size - i_b);
	target = find_target_pos_in_a(a, *(int *)n->content);
	if (target <= a->size / 2)
		c.cost_a = target;
	else
		c.cost_a = -(a->size - target);
	c.total = calc_total_cost(c.cost_a, c.cost_b);
	return (c);
}

t_cost	find_cheapest_to_push_to_a(t_stack *a, t_stack *b)
{
	t_list	*n;
	t_cost	best;
	t_cost	curr;
	int		i;

	n = b->top;
	best.total = 2147483647;
	i = 0;
	while (n)
	{
		curr = calculate_cost_to_a(a, b, n, i++);
		if (curr.total < best.total
			|| (curr.total == best.total
				&& ft_abs(curr.cost_a) + ft_abs(curr.cost_b)
				< ft_abs(best.cost_a) + ft_abs(best.cost_b)))
			best = curr;
		n = n->next;
	}
	return (best);
}
