/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:06:23 by afontain          #+#    #+#             */
/*   Updated: 2023/02/12 22:51:14 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int	nombre;

	nombre = 0;
	only3_in_a(stack_a, stack_b);
	tri_3(stack_a);
	// set_index(stack_a);
	// find_index(stack_a, content);
	nombre = calcul_nb_coup(stack_a, stack_b);
	printf("nombre = %d\n", nombre);
}
