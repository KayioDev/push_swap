/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_radix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:41:37 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/13 16:56:13 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	run_radix(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	init_stack(&b);
	a = parse_args(argc, argv);
	if (!a)
		return (1);
	compress_stack(a);
	if (!is_order(a))
	{
		if (a->size <= 3)
			sort_three(a);
		else if (a->size <= 5)
			sort_five(a, b);
		else
			radix_sort(a, b);
	}
	stack_clear(a, free);
	free(a);
	stack_clear(b, free);
	free(b);
	return (0);
}
