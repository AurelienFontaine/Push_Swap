/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:56:10 by afontain          #+#    #+#             */
/*   Updated: 2023/03/13 13:03:46 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	same_place(t_list **stack_a, t_list **stack_b, int nombre, int index)
{
	int	med_a;
	int	med_b;
	int	i;
	int	j;
	
	med_a = ft_lstsize(stack_a) / 2 + 1;
	med_b = ft_lstsize(stack_b) / 2 + 1;
	i = max(med_a, med_b);
	j = min(med_a, med_b);
	if (find_index(stack_a, nombre) > med_a && index > med_b)
	{
		while(i - j + 1 > 0)
			rrr(stack_a, stack_b);
	}
	if (find_index(stack_a, nombre) <= med_a && index <= med_b)
	{
		while(i - j + 1 > 0)
			rr(stack_a, stack_b);
	}
}
