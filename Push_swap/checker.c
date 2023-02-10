/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:43:43 by afontain          #+#    #+#             */
/*   Updated: 2023/02/10 14:16:15 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_numbers(int ac, char **av)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] > 58 || av[i][j] < 48)
				return (0);
			j++;	
		}
		i++;
	}
	return (1);
}

int	check_is_int(int ac, char **av)
{
	
	size_t	i;

	i = 0;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			return (0);
		if (ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
			return (0);
	}
	return (1);
}

int	check_doublons(int ac, char **av)
{
	size_t	i;
	size_t	j;
	
	j = 0;
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

int	check_already_sort(t_list **stack)
{
	size_t	i;
	
	i = 0;
	if (!(*stack))
		return (0);
	
	while (*stack && (*stack)->content < (*stack)->next->content)
	{
		*stack = (*stack)->next;
		i++;
	}
	if (!(*stack))
		return (1);
	return (0);
}
