/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:24:14 by afontain          #+#    #+#             */
/*   Updated: 2023/02/14 18:42:20 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arrange_a(t_list **stack_a)
{
	t_list	*tmp;
	int	i;

	i = 1;
	tmp = *stack_a;
	while(tmp->content < tmp->next->content)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < ft_lstsize(*stack_a) / 2 + 1)
	{
		while (i > 0)
			{
				rotate(stack_a, 'a');
				i--;
			}
	}
	else if (i >= ft_lstsize(*stack_a) / 2 + 1 )
	{
		while (ft_lstsize(*stack_a) - i++ > 0)
				rrba(stack_a, 'a');
	}
}

void	indexing(t_list *stack_a)
{
	t_list	*tmp;
	t_list	*head;

	head = stack_a;
	while (stack_a)
	{
		tmp = head;
		while (tmp)
		{
			if (stack_a->content > tmp->content)
				stack_a->pos_final++;
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
}

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
	indexing(*stack_a);
	return (stack_a);
}

int	parsing(int ac, char **av)
{
	if (!check_is_numbers(ac, av))
		return (0);
	if (!check_is_int(ac, av))
		return (0);
	if (!check_doublons(av))
		return (0);
	return (1);
}

// void	print_stack(t_list *stack)
// {
// 	t_list	*tmp;

// 	tmp = stack;
// 	printf("stack\n");
// 	while (tmp)
// 	{
// 		printf("%d	|	%d\n", tmp->content, tmp->pos_final);
// 		tmp = tmp->next;
// 	}
// 	printf("\n");
// }

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
	// printf("\n\n%d\n\n", check_already_sort(*stack_a));
	// print_stack(*stack_a);
	// free(stack_b);
	arrange_a(stack_a);
	// print_stack(*stack_a);
}
