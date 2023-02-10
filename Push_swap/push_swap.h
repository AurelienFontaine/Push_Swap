/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:50:58 by afontain          #+#    #+#             */
/*   Updated: 2023/02/10 14:28:42 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
} t_list;

//Main
int			parsing(int ac, char **av);
void		small_sort(t_list **stack_a, t_list **stack_b);

//Small sort
void		tri_2(t_list **stack);
void		tri_3(t_list **stack);
void		tri_4(t_list **stack_a, t_list **stack_b);

//Swap
void		swap(t_list *stack, char c);
void 		ss(t_list **stack_a, t_list **stack_b);

//Rotate
void		rotate(t_list **stack, char c);
void 		rr(t_list **stack_a, t_list **stack_b);

//Reverse rotate
void 		rrba(t_list **stack, char c);
void 		rrr(t_list **stack_a, t_list **stack_b);

//Push
void		push(t_list **stack_src, t_list **stack_dst, char c);

//Utils
long long	ft_atoi(char *str);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(char *str);

//Lst_utils
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		*ft_lstadd_back(t_list **lst, t_list *new);

#endif