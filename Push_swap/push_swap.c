/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:24:14 by afontain          #+#    #+#             */
/*   Updated: 2023/02/12 21:53:14 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**create_stacks(int ac, char **av)
{
	t_list	**stack_a;
	int		i;

	i = 1;
	stack_a = malloc(sizeof (t_list *));
	*stack_a = NULL;
	while (i < ac)
	{
		ft_lstadd_back(stack_a, ft_atoi(av[i]));
		i++;
	}
	return (stack_a);
}

int	parsing(int ac, char **av)
{
	if (!check_is_numbers(ac, av))
	{
		printf("a");
		return (0);
	}
	if (!check_is_int(ac, av))
	{
		printf("ab");
		return (0);
	}
	if (!check_doublons(av))
	{
		printf("abbb");
		return (0);
	}
	return (1);
}

void	print_stack(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	printf("stack\n");
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{	
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac <= 2)
		return (1);
	if (!parsing(ac, av))
		return (write(1, "ERROR\n", 6), 1);
	stack_a = create_stacks(ac, av);
	if (!check_already_sort(*stack_a))
		return (0);
	stack_b = malloc(sizeof(t_list *));
	// small_sort(stack_a, stack_b);
	big_sort(stack_a, stack_b);
	// print_stack(*stack_a);
	// free(stack_b);
}
