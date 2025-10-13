/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:04:57 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/13 16:39:30 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_dup(t_stack *stack, int value)
{
	t_list	*node;

	node = stack->top;
	while (node)
	{
		if (*(int *)node->content == value)
			return (1);
		node = node->next;
	}
	return (0);
}

t_stack	*log_erro(t_stack *stack, char **string)
{
	if (string)
		ft_free_split(string);
	if (stack)
	{
		stack_clear(stack, free);
		free(stack);
	}
	write(2, "Error\n", 6);
	return (NULL);
}

int	is_empity(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}
