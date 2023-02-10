/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:51:14 by afontain          #+#    #+#             */
/*   Updated: 2023/02/10 14:32:05 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_2(t_list **stack)
{
	if ((*stack)->content > (*stack)->next->content)
		swap(*stack, 'a');
}

void	tri_3(t_list **stack)
{
	if ((*stack)->content > (*stack)->next->content && 
		(*stack)->next->content > (*stack)->next->next->content)
	{
		swap(*stack,'a');
		rrba(*stack, 'a');
	}
	else if ((*stack)->next->next->content > (*stack)->next->content && 
		(*stack)->next->next->content < (*stack)->content)
		rotate(*stack, 'a');
	else if ((*stack)->content < (*stack)->next->content &&
		(*stack)->content > (*stack)->next->next->content)
		rrba(*stack, 'a');
	else if ((*stack)->content > (*stack)->next->content &&
		(*stack)->content < (*stack)->next->next->content)
		swap(*stack, 'a');
	else if ((*stack)->next->next->content < (*stack)->next->content && 
		(*stack)->next->next->content > (*stack)->content)
		{
			rrba(*stack, 'a');
			swap(*stack, 'a');
		}
}

void	tri_4(t_list **stack_a, t_list **stack_b)
{
	push(*stack_a, *stack_b, 'b');
	tri_3(*stack_a);
	push(*stack_a, *stack_b, 'a');
	if ((*stack_a)->content > (*stack_a)->next->content && 
		(*stack_a)->content < (*stack_a)->next->next->content)
		swap(*stack_a,'a');
	else if ((*stack_a)->content > (*stack_a)->next->next->next->content)
		rotate(*stack_a,'a');
	else if ((*stack_a)->content > (*stack_a)->next->next->content && 
		(*stack_a)->content < (*stack_a)->next->next->next->content)
		{
			rrba(*stack_a, 'a');
			swap(*stack_a, 'a');
			rotate(*stack_a, 'a');
			rotate(*stack_a, 'a');
		}	 
}
