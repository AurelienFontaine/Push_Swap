/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:34:52 by afontain          #+#    #+#             */
/*   Updated: 2023/03/20 19:35:13 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// #include "get_next_line.h"

t_list	**create_stacks(int ac, char **av)
{
	t_list	**stack_a;
	int		i;

	i = 1;
	stack_a = malloc(sizeof (t_list *));
	if (!stack_a)
		return (NULL);
	*stack_a = NULL;
	while (i < ac)
	{
		ft_lstadd_back(stack_a, ft_atoi(av[i]));
		i++;
	}
	indexing(*stack_a);
	return (stack_a);
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

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (!parsing(ac, av))
		return (write(STDERR_FILENO, "ERROR\n", 6), 1);
	if (ac <= 1)
		return (0);
	stack_a = create_stacks(ac, av);
	stack_b = malloc(sizeof(t_list *));
	if (!stack_b)
		return (0);
	*stack_b = NULL;
	verif(stack_a, stack_b);
	ft_free_list(stack_b);
	ft_free_list(stack_a);
}
