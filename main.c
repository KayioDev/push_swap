/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:23:25 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/06 19:10:52 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

int	main(int argc, char **argv)
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
// int	main(int argc, char **argv)
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	init_stack(&b);
// 	a = parse_args(argc, argv);
// 	if (!a)
// 		return (1);
// 	compress_stack(a);
// 	if (!is_order(a))
// 	{
// 		if (a->size <= 3)
// 			sort_three(a);
// 		else if (a->size <= 5)
// 			sort_five(a, b);
// 		else
// 			radix_sort(a, b);
// 	}
// 	stack_clear(a, free);
// 	free(a);
// 	stack_clear(b, free);
// 	free(b);
// 	return (0);
// }
