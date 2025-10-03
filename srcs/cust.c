/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cust.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 04:05:09 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/03 04:24:15 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_value(t_stack *s)
{
	t_list	*node;
	int		max;

	if (!s || !s->top)
		return (0);
	node = s->top;
	max = *(int *)node->content;
	while (node)
	{
		if (*(int *)node->content > max)
			max = *(int *)node->content;
		node = node->next;
	}
	return (max);
}

int	index_of(t_stack *s, int value)
{
	t_list	*node;
	int		index;

	if (!s || !s->top)
		return (-1);
	node = s->top;
	index = 0;
	while (node)
	{
		if (*(int *)node->content == value)
			return (index);
		node = node->next;
		index++;
	}
	return (-1);
}

int	find_min_value(t_stack *a)
{
	t_list	*node;
	int		min;

	if (!a || !a->top)
		return (0);
	node = a->top;
	min = *(int *)node->content;
	while (node)
	{
		if (*(int *)node->content < min)
			min = *(int *)node->content;
		node = node->next;
	}
	return (min);
}

void	bring_min_on_top(t_stack *a)
{
	int		min;
	int		index;
	int		i;
	t_list	*node;

	if (!a || !a->top)
		return ;
	min = find_min_value(a);
	index = 0;
	node = a->top;
	while (node)
	{
		if (*(int *)node->content == min)
			break ;
		node = node->next;
		index++;
	}
	if (index <= a->size / 2)
	{
		i = 0;
		while (i++ < index)
			ra(a);
	}
	else
	{
		i = 0;
		while (i++ < (a->size - index))
			rra(a);
	}
}
int	find_target_pos_in_a(t_stack *a, int value)
{
	t_list	*node;
	int		pos;
	int		curr;
	int		next;
	int		min = find_min_value(a);
	int		max = find_max_value(a);

	if (!a || !a->top)
		return (0);
	if (value < min || value > max)
		return index_of(a, min);
	node = a->top;
	pos = 0;
	while (node->next)
	{
		curr = *(int *)node->content;
		next = *(int *)node->next->content;
		if (value > curr && value < next)
			return (pos + 1);
		node = node->next;
		pos++;
	}
	// caso circular
	curr = *(int *)node->content;
	next = *(int *)a->top->content;
	if (value > curr && value < next)
		return (pos + 1);

	return (0);
}

int	find_target_pos_in_b(t_stack *b, int value)
{
	t_list	*node;
	int		pos;
	int		best_pos;
	int		curr;
	int		next;

	if (!b || !b->top)
		return (0);

	int min = find_min_value(b);
	int max = find_max_value(b);
	if (value < min || value > max)
		return index_of(b, max) + 1;
	node = b->top;
	pos = 0;
	best_pos = 0;
	while (node->next)
	{
		curr = *(int *)node->content;
		next = *(int *)node->next->content;
		if (value < curr && value > next)
			return (pos + 1);
		node = node->next;
		pos++;
	}
	curr = *(int *)node->content;
	next = *(int *)b->top->content;
	if (value < curr && value > next)
		return (pos + 1);

	return (0);
}

t_cost	calculate_cost(t_stack *a, t_stack *b, t_list *node, int index)
{
	t_cost	c;
	int		target_pos;

	c.node = node;
	if (index <= a->size / 2)
		c.cost_a = index;
	else
		c.cost_a = -(a->size - index);
	target_pos = find_target_pos_in_b(b, *(int *)node->content);
	if (target_pos <= b->size / 2)
		c.cost_b = target_pos;
	else
		c.cost_b = -(b->size - target_pos);
	if ((c.cost_a >= 0 && c.cost_b >= 0) || (c.cost_a < 0 && c.cost_b < 0))
		c.total = (abs(c.cost_a) > abs(c.cost_b)) ? abs(c.cost_a) : abs(c.cost_b);
	else
		c.total = abs(c.cost_a) + abs(c.cost_b);

	return (c);
}
t_cost	find_cheapest(t_stack *a, t_stack *b)
{
	t_list	*node;
	int		index;
	t_cost	best;
	t_cost	curr;

	node = a->top;
	index = 0;
	best.total = 2147483647;

	while (node)
	{
		curr = calculate_cost(a, b, node, index);
		if (curr.total < best.total)
			best = curr;
		node = node->next;
		index++;
	}
	return (best);
}
void	do_cheapest_move(t_stack *a, t_stack *b, t_cost c)
{
	while (c.cost_a > 0 && c.cost_b > 0)
	{
		rr(a, b);
		c.cost_a--;
		c.cost_b--;
	}
	while (c.cost_a < 0 && c.cost_b < 0)
	{
		rrr(a, b);
		c.cost_a++;
		c.cost_b++;
	}
	while (c.cost_a > 0) { ra(a); c.cost_a--; }
	while (c.cost_a < 0) { rra(a); c.cost_a++; }
	while (c.cost_b > 0) { rb(b); c.cost_b--; }
	while (c.cost_b < 0) { rrb(b); c.cost_b++; }
	pb(a, b);
}
void	cheapest_sort(t_stack *a, t_stack *b)
{
	t_cost	move;
	pb(a, b);
	pb(a, b);
	while (a->size > 3)
	{
		move = find_cheapest(a, b);
		do_cheapest_move(a, b, move);
	}
	sort_three(a);
	while (b->size > 0)
	{
	    int value = *(int *)b->top->content;
	    int target = find_target_pos_in_a(a, value);
	    if (target <= a->size / 2)
	        while (target--) ra(a);
	    else
	        while (target++ < a->size) rra(a);

	    pa(a, b);
	}
	bring_min_on_top(a);
}
