/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:50:58 by afontain          #+#    #+#             */
/*   Updated: 2023/03/20 19:34:53 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				pos_final;
	struct s_list	*next;
}t_list;

//Main
int			parsing(int ac, char **av);
// void		print_stack(t_list *stack);
void		small_sort(t_list **stack_a, t_list **stack_b);
void		big_sort(t_list **stack_a, t_list **stack_b);
t_list		**create_stacks(int ac, char **av);
void		indexing(t_list *stack_a);
void		arrange_a(t_list **stack_a);

//Algo_utils
void		only3_in_a(t_list **stack_a, t_list **stack_b);
void		set_index(t_list **stack);
// int			find_index(t_list *stack_a, int index);
// int			cost_r_or_rr(t_list **stack, int index);
int			calcul_nb_coup(t_list **stack_a, t_list **stack_b);

//Find_index
int			fi(t_list *stack_a, int content);

//Checker
int			check_is_numbers(int ac, char **av);
int			check_is_int(int ac, char **av);
int			check_doublons(char **av);
int			check_already_sort(t_list *stack);

//Small sort
void		tri_2(t_list **stack);
void		tri_3(t_list **stack);
void		tri_4(t_list **stack_a, t_list **stack_b);
void		small_sort(t_list **stack_a, t_list **stack_b);
// void		free_stack(t_list **stack);

//Swap
void		swap(t_list **stack, char c);
void		ss(t_list **stack_a, t_list **stack_b);

//Rotate
void		rotate(t_list **stack, char c);
void		rr(t_list **stack_a, t_list **stack_b);

//Reverse rotate
void		rrba(t_list **stack, char c);
void		rrr(t_list **stack_a, t_list **stack_b);

//Push
void		push(t_list **stack_src, t_list **stack_dst, char c);

//Utils
long long	ft_atoi(char *str);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *str);

//Lst_utils
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, int content);
void		ft_free_list(t_list **stack);

//Optimissation
void		same_place(t_list **stack_a, t_list **stack_b, int nombre);
void		only_low_in_a(t_list **stack_a, t_list **stack_b);
void		ft_sort_int_tab(int *tab, int size);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//BONUS
char		*get_next_line(int fd);
void		read_next_line(char *line, char *buffer);
char		*line_to_buffer(char *str);
char		*read_line(int fd, char *str);

char		*ft_strchr(const char *str, int c);
// int		ft_strcmp(char *s1, char *s2);

char		*ft_strjoin(char *str1, char *str2);
void		*ft_memset(void *str, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			compare(char *s1, char *s2);
int			verif(t_list **stack_a, t_list **stack_b);

#endif