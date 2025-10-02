/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:26:40 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/02 19:24:40 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct	s_cost
{
	t_list	*node;
	int		cost_a;
	int		cost_b;
	int		total;
}	t_cost;

void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

t_stack	*parse_args(int argc, char **argv);
t_stack	*log_erro(t_stack *stack, char **string);
int		is_empity(char *str);
int		is_dup(t_stack *stack, int value);
int		is_number(char *string);
void	printf_stack(t_stack *stack);
int		is_order(t_stack *stack);

void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);
void	compress_stack(t_stack *stack);

void	bubble_sort(int *arr, int size);

#endif
