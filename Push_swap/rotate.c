/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:28:38 by afontain          #+#    #+#             */
/*   Updated: 2023/02/10 14:24:21 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack, char c)
{
	t_list	*lst;
	t_list	*lst_last;
	
	lst = *stack;
	*stack = lst->next;
	lst_last = ft_lstlast(lst);
	lst_last->next = lst;
	lst_last = lst_last->next;
	lst_last->next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_b, 'x');
	rotate(stack_a, 'x');
	write(1, "rr\n", 3);
}
