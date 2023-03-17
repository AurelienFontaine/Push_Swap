/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:04:06 by afontain          #+#    #+#             */
/*   Updated: 2023/03/17 13:44:38 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index2(t_list *stack_a, int content, int i)
{
	t_list	*tmp;

	tmp = stack_a;
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

int	find_index1(t_list *stack_a, int content, int i)
{
	t_list	*tmp;
	t_list	*last;

	tmp = stack_a;
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
	return (1);
}

int	fi(t_list *stack_a, int content)
{
	int		i;
	t_list	*tmp;
	t_list	*last;

	tmp = stack_a;
	last = ft_lstlast(stack_a);
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
	if (content > last->content)
		return (find_index1(stack_a, content, i));
	return (find_index2(stack_a, content, i));
}
