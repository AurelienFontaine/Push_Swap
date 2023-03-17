/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:01:38 by afontain          #+#    #+#             */
/*   Updated: 2023/03/17 18:52:39 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

void	checker1(char *line, t_list **stack_a, t_list **stack_b)
{
		if (ft_strcmp(line, "pa\n"))
			push(stack_a, stack_b, 'c');
		else if (ft_strcmp(line, "pb\n"))
			push(stack_b, stack_a, 'c');
		else if (ft_strcmp(line, "sa\n"))
			swap(stack_a, 'c');
		else if (ft_strcmp(line, "sb\n"))
			swap(stack_b, 'c');
		else if (ft_strcmp(line, "rr\n"))
			rr(stack_a, stack_b);
		else if (ft_strcmp(line, "rrr\n"))
			rrr(stack_a, stack_b);
		else 
			write(1, "ERROR\n", 6);
}

void	checker(char *line, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(line, "ra\n"))
		rotate(stack_a, 'c');
	else if (ft_strcmp(line, "rb\n"))
		rotate(stack_b, 'c');
	else if (ft_strcmp(line, "rra\n"))
		rrba(stack_a, 'c');
	else if (ft_strcmp(line, "rrb\n"))
		rrba(stack_b, 'c');
	else 
		checker1(line, stack_a, stack_b);
}

void	verif(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		checker(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	if (check_already_sort(*stack_a))
		write(1, "OK\n", 3);
	else	
		write (1, "KO\n", 3);
}
