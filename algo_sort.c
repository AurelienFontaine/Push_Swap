/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:06:23 by afontain          #+#    #+#             */
/*   Updated: 2023/03/17 18:33:03 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_in_b1(t_list **stack_b, int index)
{
	int	i;

	i = 1;
	if (index <= ft_lstsize(*stack_b) / 2 + 1)
	{
		while (i++ < index)
			rotate(stack_b, 'b');
	}
	else if (index > ft_lstsize(*stack_b) / 2 + 1)
	{
		if (index == ft_lstsize(*stack_b))
			return (rrba(stack_b, 'b'));
		else if (ft_lstsize(*stack_b) == 2)
			return (rrba(stack_b, 'b'));
		while (i++ < ft_lstsize(*stack_b) + 2 - index)
			rrba(stack_b, 'b');
	}
}

void	op_in_b(t_list **stack_b, int nombre)
{
	int		index;
	t_list	*tmp;

	tmp = *stack_b;
	index = fi(*stack_b, nombre);
	set_index(stack_b);
	while (tmp)
	{
		if (tmp->content == nombre)
			index = tmp->index;
		tmp = tmp->next;
	}
	op_in_b1(stack_b, index);
}

void	op_in_a(t_list **stack_a, int nombre)
{
	int	i;

	i = 1;
	if (nombre <= ft_lstsize(*stack_a) / 2 + 1)
	{	
		while (i < nombre)
		{
			rotate(stack_a, 'a');
			i++;
		}
	}
	else if (nombre > ft_lstsize(*stack_a) / 2 + 1)
	{
		if (nombre == ft_lstsize(*stack_a) + 1)
			return ;
		while (i < ft_lstsize(*stack_a) + 2 - nombre)
		{
			rrba(stack_a, 'a');
			i++;
		}
	}
}

int	get_final_pos(t_list *stack, int content)
{
	while (stack)
	{
		if (stack->pos_final == content)
			return (stack->pos_final);
		stack = stack->next;
	}
	return (0);
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int	nombre;

	if (ft_lstsize(*stack_a) > 5)
	{
		only_low_in_a(stack_a, stack_b);
		only3_in_a(stack_a, stack_b);
	}
	else
		only3_in_a(stack_a, stack_b);
	tri_3(stack_a);
	while (ft_lstsize(*stack_b) > 0)
	{
		nombre = calcul_nb_coup(stack_a, stack_b);
		same_place(stack_a, stack_b, nombre);
		nombre = calcul_nb_coup(stack_a, stack_b);
		op_in_b(stack_b, nombre);
		op_in_a(stack_a, fi(*stack_a, nombre));
		set_index(stack_a);
		push(stack_b, stack_a, 'a');
	}
}
