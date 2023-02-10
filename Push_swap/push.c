/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:36:28 by afontain          #+#    #+#             */
/*   Updated: 2023/02/10 14:29:29 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_list **stack_src, t_list **stack_dst, char c)
{
	t_list	*lst_src;
	t_list	*lst_dst;
	t_list	*tmp;

	lst_dst = *stack_dst;
	lst_src = *stack_src;
	tmp = lst_src;
	lst_src = lst_src->next;
	*stack_src = lst_src;
	tmp->next = lst_dst;
	*stack_dst = tmp;
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}
