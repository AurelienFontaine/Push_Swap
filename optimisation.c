/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:56:10 by afontain          #+#    #+#             */
/*   Updated: 2023/03/14 19:44:03 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	only3_in_a(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int size;

	i = 0;
	size = ft_lstsize(*stack_a);
	while (i < size - 3)
	{
		push(stack_a, stack_b, 'b');
		i++;
	}
}

void	only_low_in_a(t_list **stack_a, t_list **stack_b)
{
	int *str;
	int	i;
	const t_list	*tmp = *stack_a;
	const int	size = ft_lstsize((t_list *)tmp);
	
	i = 0;
	str = malloc(sizeof(int) * size);
	if (!str)
		return ;
	while (i < size)
	{
		str[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	ft_sort_int_tab(str, size);
	while (ft_lstsize(*stack_b) != (size / 2))
	{
		if ((*stack_a)->content < str[size / 2])
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a, 'a');
	}
	free(str);
}

int	mini(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	find_index_b(t_list *stack_b, int nombre)
{
	while (stack_b && stack_b->content != nombre)
		stack_b = stack_b->next;
	return (stack_b->index);
}

void	same_place(t_list **stack_a, t_list **stack_b, int nombre)
{
	int	i;
	int	j;
	int k;
	int	z;
	int	q;
	
	z = ft_lstsize(*stack_a) / 2 + 1;
	q = ft_lstsize(*stack_b) / 2 + 1;
	j = ft_lstsize(*stack_a);
	k = ft_lstsize(*stack_b);
	if (find_index(*stack_a, nombre) > z && 
		find_index_b(*stack_b, nombre) > q)
	{
		i = mini(j - find_index(*stack_a, nombre) + 1, k - find_index_b(*stack_b, nombre) + 1);
		while(i-- > 0)
			rrr(stack_a, stack_b);
	}
	if (find_index(*stack_a, nombre) <= z
		&& find_index_b(*stack_b, nombre) <= q)
	{
		i = mini(find_index(*stack_a, nombre) - 1 , find_index_b(*stack_b, nombre) - 1);
		while(i-- > 0)
			rr(stack_a, stack_b);
	}		
}
