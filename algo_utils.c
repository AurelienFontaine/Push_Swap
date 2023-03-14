/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:54:11 by afontain          #+#    #+#             */
/*   Updated: 2023/03/14 20:02:40 by afontain         ###   ########.fr       */
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

 //+25 lignes
int	find_index(t_list *stack_a, int content)
{
	int		i;
	t_list	*tmp;
	t_list	*last;

	tmp = stack_a;
	i = 1;
	//Cas dans l'ordre
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
	//Cas plus grand que tous
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
	//Reste 
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
	int		cost;
	int		choix;
	int 	nombre;
	t_list	*tmp1;

	cost = 0;
	set_index(stack_a);
	set_index(stack_b);
	tmp1 = *stack_b;
	cost = put_b(stack_b, tmp1->index) + put_a(stack_a, find_index(*stack_a, tmp1->content)) + 1;
	choix = cost;
	nombre = tmp1->content;
	tmp1 = tmp1->next;
	while (tmp1)
	{
		cost = put_b(stack_b, tmp1->index) + put_a(stack_a, find_index(*stack_a, tmp1->content)) + 1;
		if (choix > cost)
		{
			nombre = tmp1->content;
			choix = cost;
		}
		tmp1 = tmp1->next;
	}
	return (nombre);
}
