/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:53:03 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/13 16:43:41 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_stack *a, t_stack *b)
{
	void	*content;

	if (!b || !b->top)
		return ;
	content = pop(b);
	push(a, content);
}

void	pb(t_stack *a, t_stack *b)
{
	void	*content;

	if (!a || !a->top)
		return ;
	content = pop(a);
	push(b, content);
}
