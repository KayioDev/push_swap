/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:23:36 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/02 17:32:55 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack *stack)
{
	int		*arr;
	t_list	*node;
	int		i;

	arr = malloc(sizeof(int) * stack->size);
	if (!arr)
		return (NULL);
	node = stack->top;
	i = 0;
	while (node)
	{
		arr[i] = *(int *)node->content;
		node = node->next;
		i++;
	}
	return (arr);
}

static int	find_index(int *arr, int size, int value)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	compress_stack(t_stack *stack)
{
	int		*arr;
	t_list	*node;
	int		value;
	int		index;

	arr = stack_to_array(stack);
	if (!arr)
		return ;
	bubble_sort(arr, stack->size);
	node = stack->top;
	while (node)
	{
		value = *(int *)node->content;
		index = find_index(arr, stack->size, value);
		*(int *)node->content = index;
		node = node->next;
	}
	free(arr);
}
