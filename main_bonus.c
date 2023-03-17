/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:34:52 by afontain          #+#    #+#             */
/*   Updated: 2023/03/17 18:53:42 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	main_bonus(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (!parsing(ac, av))
		return (write(1, "ERROR\n", 6), 1);
	if (ac <= 2)
		return (0);
	stack_a = create_stacks(ac, av);
	if (!check_already_sort(*stack_a))
		return (ft_free_list(stack_a), 1);
	stack_b = malloc(sizeof(t_list *));
	if (!stack_b)
		return (0);
	*stack_b = NULL;
	if (ac == 3 || ac == 4)
		small_sort(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
	if (!check_already_sort(*stack_a))
		return (ft_free_list(stack_b), ft_free_list(stack_a), 0);
	arrange_a(stack_a);
	verif(stack_a, stack_b);
	ft_free_list(stack_b);
	ft_free_list(stack_a);
	return (0);
}
