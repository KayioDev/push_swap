/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:53:03 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/10 18:29:45 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	void	*content;

	if (!b || !b->top)
		return ;
	content = pop(b);
	push(a, content);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	void	*content;

	if (!a || !a->top)
		return ;
	content = pop(a);
	push(b, content);
	write(1, "pb\n", 3);
}
