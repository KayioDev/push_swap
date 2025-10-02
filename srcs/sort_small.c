/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:25:34 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/02 17:26:12 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_utils(t_stack *a, int f, int s, int t)
{
	if (f > s && s < t && f < t)
		sa(a);
	else if (f > s && s > t)
	{
		sa(a);
		rra(a);
	}
	else if (f > s && s < t && f > t)
		ra(a);
	else if (f < s && s > t && f < t)
	{
		sa(a);
		ra(a);
	}
	else if (f < s && s > t && f > t)
		rra(a);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (a->size == 2)
	{
		first = *(int *)a->top->content;
		second = *(int *)a->top->next->content;
		if (first > second)
			sa(a);
		return ;
	}
	first = *(int *)a->top->content;
	second = *(int *)a->top->next->content;
	third = *(int *)a->top->next->next->content;
	sort_three_utils(a, first, second, third);
}

int	find_min_index(t_stack *a)
{
	t_list	*node;
	int		min;
	int		index;
	int		min_index;

	node = a->top;
	min = *(int *)node->content;
	index = 0;
	min_index = 0;
	while (node)
	{
		if (*(int *)node->content < min)
		{
			min = *(int *)node->content;
			min_index = index;
		}
		node = node->next;
		index++;
	}
	return (min_index);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min_index;

	while (a->size > 3)
	{
		min_index = find_min_index(a);
		if (min_index == 0)
			pb(a, b);
		else if (min_index <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
