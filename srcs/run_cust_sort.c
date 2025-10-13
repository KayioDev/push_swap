/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cust_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:45:41 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/13 16:55:54 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	run_cust_sort(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	init_stack(&b);
	a = parse_args(argc, argv);
	if (!a)
		return (1);
	if (!is_order(a))
	{
		compress_stack(a);
		if (a->size <= 3)
			sort_three(a);
		else if (a->size <= 5)
			sort_five(a, b);
		else
		{
			cheapest_sort(a, b);
			bring_min_on_top(a);
		}
	}
	stack_clear(a, free);
	stack_clear(b, free);
	free(a);
	free(b);
	return (0);
}
