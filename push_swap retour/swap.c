/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:47:39 by afontain          #+#    #+#             */
/*   Updated: 2023/02/12 18:08:18 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char c)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = (*stack)->content;
	j = (*stack)->index;
	tmp = (*stack)->next;
	(*stack)->content = tmp->content;
	(*stack)->index = tmp->index;
	tmp->content = i;
	tmp->index = j;
	// *stack = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_b, 'x');
	swap(stack_a, 'x');
	write(1, "ss\n", 3);
}
