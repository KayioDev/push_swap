/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:13:01 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/02 17:28:59 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_and_push(t_stack *stack, char **split_args, int j)
{
	long	value;
	int		*num;

	if (!is_number(split_args[j]))
		return (0);
	value = ft_atol(split_args[j]);
	if (value < INT_MIN || value > INT_MAX)
		return (0);
	if (is_dup(stack, (int)value))
		return (0);
	if (is_empity(split_args[j]))
		return (0);
	num = malloc(sizeof(int));
	if (!num)
		return (0);
	*num = (int)value;
	push(stack, num);
	return (1);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*stack;
	char	**split_args;
	int		i;
	int		j;

	init_stack(&stack);
	i = argc - 1;
	while (i > 0)
	{
		split_args = ft_split(argv[i], ' ');
		j = 0;
		while (split_args[j])
			j++;
		j--;
		while (j >= 0)
		{
			if (!check_and_push(stack, split_args, j))
				return (log_erro(stack, split_args));
			j--;
		}
		ft_free_split(split_args);
		i--;
	}
	return (stack);
}
