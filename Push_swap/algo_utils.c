/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:54:11 by afontain          #+#    #+#             */
/*   Updated: 2023/02/12 23:10:38 by afontain         ###   ########.fr       */
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
	int	i;
	t_list	*tmp;

	tmp = stack_a;
	i = 1;
	while (tmp && content > (tmp)->content)
	{
		tmp = (tmp)->next;
		i++;
	}
	return (i);
}

//recode cette fonction pour quelle return le bon nombre de coups a gauche
//a la limite tu fais une fonction pour la droite et une pour la gauche
int	rot_or_reverse(t_list **stack, int index)
{
	int	med;

	med = ft_lstsize(*stack) / 2 + 1;
	if (index <= med)
		return (index - 1);
	else if (index > med)
		return (ft_lstsize(*stack) - index + 1);
	return (0);
}

int	calcul_nb_coup(t_list **stack_a, t_list **stack_b)
{
	int		cost;
	int		choix;
	int 	nombre;
	t_list	*tmp;

	cost = 0;
	choix = 0;
	set_index(stack_a);
	set_index(stack_b);
	tmp = *stack_b;
	cost = rot_or_reverse(stack_b, tmp->index);
	if (find_index(*stack_a, tmp->content) == 2)
		cost += 2;
	else if (find_index(*stack_a, tmp->content)== 1)
		cost += 1;
	else
		cost += rot_or_reverse(stack_a, find_index(*stack_a, tmp->content)) * 2 + 2;
	choix = cost;
	printf("content = [%d]	|	coups = %d\n", tmp->content, cost);
	nombre = tmp->content;
	tmp = tmp->next;
	while (tmp)
	{
		cost = rot_or_reverse(stack_b, tmp->index);
		if (find_index(*stack_a, tmp->content) == 2)
			cost += 2;
		else if (find_index(*stack_a, tmp->content) == 1)
			cost += 1;
		else
			cost += rot_or_reverse(stack_a, find_index(*stack_a, tmp->content)) * 2 + 1;
		printf("content = [%d]	|	coups = %d\n", tmp->content, cost);
		if (choix > cost)
		{
			nombre = tmp->content;
			choix = cost;
		}
		tmp = tmp->next;
	}
	return (nombre);
}
