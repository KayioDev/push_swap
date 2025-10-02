/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:17:16 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/02 17:30:39 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_bit(t_stack *a, t_stack *b, int bit, int size)
{
	int	j;
	int	num;

	j = 0;
	while (j < size)
	{
		num = *(int *)a->top->content;
		if ((num >> bit) & 1)
			ra(a);
		else
			pb(a, b);
		j++;
	}
	while (b->size > 0)
		pa(a, b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	size;
	int	max_num;
	int	max_bits;

	i = 0;
	size = a->size;
	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		process_bit(a, b, i, a->size);
		i++;
	}
}
