/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:43:43 by afontain          #+#    #+#             */
/*   Updated: 2023/02/12 18:26:28 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_numbers(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-' && av[i][j + 1])
			j++;
		while (av[i][j])
		{
			if (av[i][j] > '9' || av[i][j] < '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_is_int(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			return (0);
		if (ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	check_doublons(char **av)
{
	int	i;
	int	j;

	j = 1;
	while (av[j])
	{
		i = j + 1;
		while (av[i])
		{
			if (ft_atoi(av[j]) == ft_atoi(av[i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	check_already_sort(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack->next && stack->content < stack->next->content)
		stack = stack->next;
	if (!stack)
		return (0);
	return (1);
}
