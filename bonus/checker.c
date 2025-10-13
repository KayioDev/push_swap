/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:54:13 by klima-do          #+#    #+#             */
/*   Updated: 2025/10/13 16:54:14 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_command_push(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "pb\n", 3) == 0)
		return (pb(a, b), 1);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		return (pa(a, b), 1);
	return (0);
}

int	get_command_swap(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		return (sa(a), 1);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		return (sb(b), 1);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		return (ss(a, b), 1);
	return (0);
}

int	get_command_rotate(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "ra\n", 3) == 0)
		return (ra(a), 1);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		return (rb(b), 1);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		return (rr(a, b), 1);
	return (0);
}

int	get_command_reverse(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "rra\n", 4) == 0)
		return (rra(a), 1);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		return (rrb(b), 1);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		return (rrr(a, b), 1);
	return (0);
}

void	checker_bonus(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!get_command_push(line, a, b)
			&& !get_command_swap(line, a, b)
			&& !get_command_rotate(line, a, b)
			&& !get_command_reverse(line, a, b))
		{
			write(2, "Error\n", 6);
			free(line);
			exit(127);
		}
		free(line);
		line = get_next_line(0);
	}
}
