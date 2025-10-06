/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:10:00 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/06 18:54:48 by klima-do         ###   ########.fr       */
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

int	find_min_value(t_stack *s)
{
	t_list	*node;
	int		min;

	if (!s || !s->top)
		return (0);
	node = s->top;
	min = *(int *)node->content;
	while (node)
	{
		if (*(int *)node->content < min)
			min = *(int *)node->content;
		node = node->next;
	}
	return (min);
}

int	index_of(t_stack *s, int value)
{
	t_list	*node;
	int		i;

	if (!s || !s->top)
		return (-1);
	node = s->top;
	i = 0;
	while (node)
	{
		if (*(int *)node->content == value)
			return (i);
		node = node->next;
		i++;
	}
	return (-1);
}
