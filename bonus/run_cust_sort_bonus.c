/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cust_sort_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:45:41 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/13 16:54:46 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	run_cust_sort_bonus(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	init_stack(&b);
	a = parse_args(argc, argv);
	checker_bonus(a, b);
	check_results(a, b);
	return (0);
}
