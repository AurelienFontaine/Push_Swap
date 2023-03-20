/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:30:32 by afontain          #+#    #+#             */
/*   Updated: 2023/03/20 14:36:03 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// #include "get_next_line.h"
// #include <stdlib.h>
// #include <stdio.h>

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i])
// 		i++;
// 	return (i);
// }

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&((char *)str)[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)str)[i] = c;
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;

	str = NULL;
	if (size * nmemb == 0 || nmemb <= SIZE_MAX / size)
		str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_memset(str, 0, nmemb * size);
	return (str);
}
