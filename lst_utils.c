/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:04:35 by afontain          #+#    #+#             */
/*   Updated: 2023/03/17 13:13:47 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	tmp = lst;
	i = 0;
	if (!tmp)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lst_new(int content)
{
	t_list	*lst_new;

	lst_new = malloc(sizeof(t_list));
	if (!lst_new)
		return (NULL);
	lst_new->content = content;
	lst_new->index = 0;
	lst_new->pos_final = 1;
	lst_new->next = NULL;
	return (lst_new);
}

void	ft_lstadd_back(t_list **lst, int content)
{
	if (!*lst)
		*lst = ft_lst_new(content);
	else
		ft_lstlast(*lst)->next = ft_lst_new(content);
}

void	ft_free_list(t_list **stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	*stack = NULL;
	free(stack);
}
