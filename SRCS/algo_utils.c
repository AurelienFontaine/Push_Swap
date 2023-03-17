/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:54:11 by afontain          #+#    #+#             */
/*   Updated: 2023/03/17 13:44:25 by afontain         ###   ########.fr       */
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

	if (index == 1)
	{
		return (0);
	}
	if (index == 2)
	{
		return (1);
	}
	med = ft_lstsize(*stack_a) / 2 + 1;
	if (index >= med)
	{
		return (ft_lstsize(*stack_a) - index + 1);
	}
	else
	{
		return (index);
	}
	return (0);
}

int	calcul_nb_coup(t_list **stack_a, t_list **stack_b)
{
	int				cost;
	int				choix;
	int				nombre;
	const t_list	*tmp = *stack_b;

	cost = 0;
	set_index(stack_a);
	set_index(stack_b);
	cost = put_b(stack_b, tmp->index)
		+ put_a(stack_a, fi(*stack_a, tmp->content)) + 1;
	choix = cost;
	nombre = tmp->content;
	tmp = tmp->next;
	while (tmp)
	{
		cost = put_b(stack_b, tmp->index)
			+ put_a(stack_a, fi(*stack_a, tmp->content)) + 1;
		if (choix > cost)
		{
			nombre = tmp->content;
			choix = cost;
		}
		tmp = tmp->next;
	}
	return (nombre);
}
