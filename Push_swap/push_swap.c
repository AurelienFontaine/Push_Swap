/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:24:14 by afontain          #+#    #+#             */
/*   Updated: 2023/02/10 14:31:34 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(int ac, char **av)
{
	t_list	**stack;
	
	if (!check_is_numbers(ac, av));
		return (0);
	if (!check_is_int(ac, av))
		return (0);
	if (!check_doublons(ac, av))
		return (0);
	if (!check_already_sort(*stack))
		return (0);
	return (1);
}

void	small_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		tri_2(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		tri_3(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		tri_4(stack_a, stack_b);
}

int main(int ac, char **av)
{	
	t_list	**stack_a;
	t_list	**stack_b;
	
	if (ac <= 2)
		return (0);
	if (!parsing(ac, av))
		return (write(1, "ERROR\n", 6), 1);
	stack_a = malloc(sizeof(t_list *));
	stack_b = malloc(sizeof(t_list *));
	big_sort(stack_a);
}
