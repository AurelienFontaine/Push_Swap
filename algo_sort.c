/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:06:23 by afontain          #+#    #+#             */
/*   Updated: 2023/03/13 20:10:25 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_in_b(t_list **stack_b, int nombre)
{
	int	i;
	int	index;
	t_list *tmp = *stack_b;

	i = 1;
	index = find_index(*stack_b, nombre);
	set_index(stack_b);
	while (tmp)
	{
		if (tmp->content == nombre)
			index = tmp->index;
		tmp = tmp->next;
	}
	// printf("nombre = %d	index = %d\n", nombre, index);
	if (index <= ft_lstsize(*stack_b) / 2 + 1)
	{
		while (i++ < index)
		// {
			rotate(stack_b, 'b');
		// 	i++;
		// }
	}
	else if (index > ft_lstsize(*stack_b) / 2 + 1)
	{
		if (index == ft_lstsize(*stack_b))
			return (rrba(stack_b, 'b'));
		else if (ft_lstsize(*stack_b) == 2)
			return (rrba(stack_b, 'b'));
		while (i++ < ft_lstsize(*stack_b) + 2 - index)
		// {
			rrba(stack_b, 'b');
		// 	i++;
		// }
	}
}

void	op_in_a(t_list **stack_a, int nombre)
{
	int	i;
	// int	index;

	i = 1;
	// nombre = find_index(*stack_a, nombre);
	// index = find_index(*stack_a, nombre);
	// printf("(rot a) nombre = %d	index = %d\n", nombre, index);
	// if (index == 1 || index == 2)
	// 	return ;
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
			// printf("RENTRE IN RRBA");
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
	// int index;

	// nombre = 0;
	only_low_in_a(stack_a, stack_b);
	only3_in_a(stack_a, stack_b);
	// printf("%d\n", j);
	tri_3(stack_a);
	// t_list	*tmp = *stack_b;
	// while (tmp)
	// {
	// 	find_index(*stack_a, tmp->pos_final, tmp->content);
	// 	tmp = tmp->next;
	// }
	// calcul_nb_coup(stack_a, stack_b);
	// calcul_nb_coup(stack_a, stack_b);
	// printf("yo\n");
	// print_stack(*stack_a);
	// print_stack(*stack_b);
	// printf("yo\n");
	while (ft_lstsize(*stack_b) > 0)
	{
		nombre = calcul_nb_coup(stack_a, stack_b);
		// printf("\nnombre = %d\n", nombre);
		same_place(stack_a, stack_b, nombre);
		nombre = calcul_nb_coup(stack_a, stack_b);
		op_in_b(stack_b, nombre);
		// printf("\n\n\nAPRES OP B\n");
		// print_stack(*stack_a);
		// print_stack(*stack_b);
		// printf("\n\n\nOP A\n");
		op_in_a(stack_a, find_index(*stack_a, nombre));
		// print_stack(*stack_a);
		// print_stack(*stack_b);
		// set_index(stack_a);
		push(stack_b, stack_a, 'a');
		// printf("\n\n\nAPRES PUSH\n");
		// print_stack(*stack_a);
		// print_stack(*stack_b);
		// printf("\n\n\nAPRES REV OP A\n");
		// print_stack(*stack_a);
		// print_stack(*stack_b);
	}
}
