/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:26:40 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/06 18:55:18 by klima-do         ###   ########.fr       */
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

/* ------------------------------- STRUCTS ---------------------------------- */

typedef struct s_cost
{
	t_list	*node;
	int		cost_a;
	int		cost_b;
	int		total;
}	t_cost;

/* ------------------------------- OPERATIONS ------------------------------- */

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* ----------------------------- PARSING & UTILS ---------------------------- */

t_stack	*parse_args(int argc, char **argv);
t_stack	*log_erro(t_stack *stack, char **split);
int		is_empity(char *str);
int		is_dup(t_stack *stack, int value);
int		is_number(char *str);
void	printf_stack(t_stack *stack);
int		is_order(t_stack *stack);
void	compress_stack(t_stack *stack);
void	bubble_sort(int *arr, int size);

/* ----------------------------- SMALL SORTS -------------------------------- */

void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

/* ----------------------------- FIND UTILS --------------------------------- */

int		find_min_value(t_stack *s);
int		find_max_value(t_stack *s);
int		index_of(t_stack *s, int value);

/* ----------------------------- POSITION UTILS ----------------------------- */

void	bring_min_on_top(t_stack *a);
int		find_target_pos_in_a(t_stack *a, int value);
int		find_target_pos_in_b(t_stack *b, int value);

/* ------------------------------ COST UTILS -------------------------------- */

t_cost	calculate_cost(t_stack *a, t_stack *b, t_list *n, int index);
t_cost	find_cheapest(t_stack *a, t_stack *b);
t_cost	calculate_cost_to_a(t_stack *a, t_stack *b, t_list *n, int index_b);
t_cost	find_cheapest_to_push_to_a(t_stack *a, t_stack *b);

/* ------------------------------- MOVES ------------------------------------ */

void	do_cheapest_move(t_stack *a, t_stack *b, t_cost c);
void	do_cheapest_move_to_a(t_stack *a, t_stack *b, t_cost c);

/* ------------------------------- SORTING ---------------------------------- */

void	push_chunks(t_stack *a, t_stack *b);
void	cheapest_sort(t_stack *a, t_stack *b);

#endif
