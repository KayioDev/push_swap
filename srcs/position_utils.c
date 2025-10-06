/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:10:00 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/06 19:02:57 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_lim
{
	int	min;
	int	max;
}	t_lim;

void	bring_min_on_top(t_stack *a)
{
	int		min;
	int		index;
	t_list	*node;

	if (!a || !a->top)
		return ;
	min = find_min_value(a);
	node = a->top;
	index = 0;
	while (node && *(int *)node->content != min)
	{
		node = node->next;
		index++;
	}
	if (index <= a->size / 2)
		while (index-- > 0)
			ra(a);
	else
	{
		index = a->size - index;
		while (index-- > 0)
			rra(a);
	}
}

static int	find_wrap_a(t_stack *a, int value, int pos, t_list *node)
{
	int	curr;
	int	next;

	curr = *(int *)node->content;
	next = *(int *)a->top->content;
	if (value > curr && value < next)
		return (pos + 1);
	return (0);
}

int	find_target_pos_in_a(t_stack *a, int value)
{
	t_list	*node;
	int		pos;
	int		curr;
	int		next;
	t_lim	lim;

	if (!a || !a->top)
		return (0);
	lim.min = find_min_value(a);
	lim.max = find_max_value(a);
	if (value < lim.min || value > lim.max)
		return (index_of(a, lim.min));
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
	return (find_wrap_a(a, value, pos, node));
}

static int	find_wrap_b(t_stack *b, int value, int pos, t_list *node)
{
	int	curr;
	int	next;

	curr = *(int *)node->content;
	next = *(int *)b->top->content;
	if (value < curr && value > next)
		return (pos + 1);
	return (0);
}

int	find_target_pos_in_b(t_stack *b, int value)
{
	t_list	*node;
	int		pos;
	int		curr;
	int		next;
	t_lim	lim;

	if (!b || !b->top)
		return (0);
	lim.min = find_min_value(b);
	lim.max = find_max_value(b);
	if (value < lim.min || value > lim.max)
		return ((index_of(b, lim.max) + 1) % b->size);
	node = b->top;
	pos = 0;
	while (node->next)
	{
		curr = *(int *)node->content;
		next = *(int *)node->next->content;
		if (value < curr && value > next)
			return (pos + 1);
		node = node->next;
		pos++;
	}
	return (find_wrap_b(b, value, pos, node));
}
