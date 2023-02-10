/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:06:23 by afontain          #+#    #+#             */
/*   Updated: 2023/02/10 15:17:03 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fusion(t_list *lst1, int P, t_list *lst2, int Q)
{
	int i;

	i = 0;
	while (i < lst_size(lst1))
	{
		if (lst1->next->content > lst2->next->content)
			swap()
	}
}

int main() 
{
  int  nbr, i, tab[100], tmp[100];
 
  printf(" Entrez le nombre d'éléments dans le tableau: ");
  scanf("%d", &nbr);
 
  printf(" Entrez %d entiers : ", nbr);
 
  for (i = 0; i < nbr; i++)
    scanf("%d", &tab[i]);
 
  triFusion(0, nbr-1, tab, tmp);
 
  printf("\n Tableau trié : ");
  for(i = 0; i < nbr; i++)  {
     printf(" %4d", tab[i]);
  }
  printf("\n");
  return 0;
}
