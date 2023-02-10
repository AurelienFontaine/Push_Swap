/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:29:29 by afontain          #+#    #+#             */
/*   Updated: 2023/02/10 14:27:11 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rrba(t_list **stack, char c)
{
	t_list	*lst;
	t_list	*lst_last;
	t_list	*lst_before_last;
	
	lst_before_last = *stack;
	while(lst_before_last->next->next)
		lst_before_last = lst_before_last->next;
	lst_last = lst_before_last->next;
	lst_before_last->next = NULL;
	lst_last->next = lst;
	*stack = lst_last;
	if (c == 'b')
		write(1, "rrb\n", 4);
	else if (c == 'a')
		write(1, "rra\n", 4);
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	rrba(stack_b, 'x');
	rrba(stack_a, 'x');
	write(1, "rrr\n", 4);
}
