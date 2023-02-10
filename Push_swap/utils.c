/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:24:59 by afontain          #+#    #+#             */
/*   Updated: 2023/02/10 13:40:44 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	k;
	char	*str;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!str)
		return (NULL);
	while (str1[i])
		str[k++] = str1[i++];
	i = 0;
	while (s2[i])
		str[k++] = str2[i++];
	str[k] = '\0';
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


