/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:24:59 by afontain          #+#    #+#             */
/*   Updated: 2023/03/20 12:45:23 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	k;
	char	*str;

	i = 0;
	k = 0;
	if (!str1 || !str2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!str)
		return (NULL);
	while (str1[i])
		str[k++] = str1[i++];
	i = 0;
	while (str2[i])
		str[k++] = str2[i++];
	str[k] = '\0';
	free(str1);
	return (str);
}

long long	ft_atoi(char *str)
{
	size_t		i;
	long long	nb;
	int			signe;

	i = 0;
	nb = 0;
	signe = 1;
	if (str[i] != 0)
	{	
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				signe = signe * -1;
			i++;
		}
		while (str[i] && str[i] <= '9' && str[i] >= '0')
		{
			nb = nb * 10 + str[i] - '0';
			i++;
		}
	}
	return (nb * signe);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a < size)
	{
		b = a + 1;
		while (b < size)
		{
			if (tab[a] > tab[b])
			{
				c = tab[a];
				tab[a] = tab[b];
				tab[b] = c;
			}
			b++;
		}
		a++;
	}
}
