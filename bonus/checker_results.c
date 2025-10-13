/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_results.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:08:41 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/13 16:54:59 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_results(t_stack *a, t_stack *b)
{
	if (!is_order(a) || b->size > 0)
	{
		printf("KO");
		return (1);
	}
	else
	{
		printf ("OK");
		return (0);
	}
}
