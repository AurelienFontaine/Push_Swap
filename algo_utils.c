/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:54:11 by afontain          #+#    #+#             */
/*   Updated: 2023/03/13 14:52:36 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	tmp->index = 1;
	while (tmp->next)
	{
		tmp->next->index = tmp->index + 1;
		tmp = tmp->next;
	}
}

int	find_index(t_list *stack_a, int content)
{
	int		i;
	t_list	*tmp;

	tmp = stack_a;
	i = 1;
	if (!check_already_sort(stack_a))
	{
		while (tmp)
		{
			if (content < tmp->content)
				return (i);
			i++;
			tmp = tmp->next;
		}
		return (1);
	}
	t_list	*last;
	last = ft_lstlast(stack_a);
	if (content > last->content)
	{
		while (tmp && content > tmp->content)
		{
			if (tmp->next && tmp->content > tmp->next->content)
			{
				i++;
				break ;
			}
			tmp = tmp->next;
			i++;	
		}
		return (i);
	}
	while (tmp && tmp->next && tmp->content < tmp->next->content)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = tmp->next;
	i++;
	while (tmp && content > tmp->content)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	put_b(t_list **stack, int index)
{
	int	med;
	
	med = ft_lstsize(*stack) / 2 + 1;
	if (index <= med)
		return (index - 1);
	else if (index > med)
		return (ft_lstsize(*stack) - index + 1);
	return (0);
}

int	put_a(t_list **stack_a, int index)
{
	int	med;
	
	// index = find_index(*stack_a, index);
	if (index == 1)
	{
		// printf("index == 1\n");
		return (0);
	}
	if (index == 2)
	{
		// printf("index == 2\n");
		return (1);
	}
	med = ft_lstsize(*stack_a) / 2 + 1;
	if (index >= med)
	{
		// printf("AUTRES : \n");
		return (ft_lstsize(*stack_a) - index + 1);
	}
	else
	{
		// printf ("INDEX:\n");
		return (index);
	}
	// if (index <= med && index == 1)
	// 	return (0);
	// else if (index <= med && index == 2)
	// 	return (1);
	// else if (index <= med)
	// 	return (2*(index - 1));
	// else if (index > med && index == ft_lstsize(*stack) + 1)
	// 	return (1);
	// else if (index > med)
	// 	return ((ft_lstsize(*stack) - index + 1) + 1);
	return (0);
}

int	calcul_nb_coup(t_list **stack_a, t_list **stack_b)
{
	int		cost;
	int		choix;
	int 	nombre;
	t_list	*tmp1;

	cost = 0;
	choix = 0;
	set_index(stack_a);
	set_index(stack_b);
	tmp1 = *stack_b;
	cost = put_b(stack_b, tmp1->index) + put_a(stack_a, find_index(*stack_a, tmp1->content)) + 1;

	choix = cost;
	// printf("content = [%d]	|	coups = %d\n", tmp1->content, cost);
	nombre = tmp1->content;
	tmp1 = tmp1->next;
	while (tmp1)
	{
		cost = put_b(stack_b, tmp1->index) + put_a(stack_a, find_index(*stack_a, tmp1->content)) + 1;
		// printf("content = [%d]	|	coups = %d\n", tmp1->content, cost);
		if (choix > cost)
		{
			nombre = tmp1->content;
			choix = cost;
		}
		tmp1 = tmp1->next;
	}
	return (nombre);
}
