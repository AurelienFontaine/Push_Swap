/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:30:32 by afontain          #+#    #+#             */
/*   Updated: 2023/03/17 16:13:53 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

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
