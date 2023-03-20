/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:01:38 by afontain          #+#    #+#             */
/*   Updated: 2023/03/20 19:38:02 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	checker2(char *line, t_list **stack_a, t_list **stack_b)
{
	if (compare(line, "sb\n"))
	{
		if (ft_lstsize(*stack_b) == 1)
			return (0);
		return (swap(stack_b, 'c'), 0);
	}	
	else if (compare(line, "rr\n"))
	{
		if (ft_lstsize(*stack_a) == 0 && ft_lstsize(*stack_b) == 0)
			return (0);
		return (rr(stack_a, stack_b), 0);
	}	
	else if (compare(line, "rrr\n"))
	{
		if (ft_lstsize(*stack_a) == 0 && ft_lstsize(*stack_b) == 0)
			return (0);
		return (rrr(stack_a, stack_b), 0);
	}	
	else
		return (write(STDERR_FILENO, "ERROR\n", 6), 6);
}

int	checker1(char *line, t_list **stack_a, t_list **stack_b)
{
	if (compare(line, "pa\n"))
	{
		if (*stack_b == NULL)
			return (0);
		return (push(stack_b, stack_a, 'c'), 0);
	}
	else if (compare(line, "pb\n"))
	{
		if (*stack_a == NULL)
			return (0);
		return (push(stack_a, stack_b, 'c'), 0);
	}
	else if (compare(line, "sa\n"))
	{
		if (ft_lstsize(*stack_a) == 1)
			return (0);
		return (swap(stack_a, 'c'), 0);
	}
	else
		return (checker2(line, stack_a, stack_b));
}

int	checker(char *line, t_list **stack_a, t_list **stack_b)
{
	if (compare(line, "ra\n"))
		return (rotate(stack_a, 'c'), 0);
	else if (compare(line, "rb\n") && *stack_b)
		return (rotate(stack_b, 'c'), 0);
	else if (compare(line, "rra\n"))
		return (rrba(stack_a, 'c'), 0);
	else if (compare(line, "rrb\n") && *stack_b)
		return (rrba(stack_b, 'c'), 0);
	else
		return (checker1(line, stack_a, stack_b));
}

int	verif(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (checker(line, stack_a, stack_b) == 6)
			return (free(line), 1);
		free(line);
		line = get_next_line(0);
	}
	if (!check_already_sort(*stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
