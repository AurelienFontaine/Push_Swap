/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:07:48 by afontain          #+#    #+#             */
/*   Updated: 2023/03/20 14:36:07 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
#include "../push_swap.h"
// int	ft_strcmp(char *s1, char *s2)
// {
// 	size_t			i;

// 	i = 0;
// 	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
// 		i++;
// 	return (s1[i] - s2[i]);
// }

int	compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (!s1[i] && !s2[i])
		return (1);
	return (0);
}

char	*read_line(int fd, char *buffer)
{
	char	*str;
	int		reade;

	reade = 1;
	if (buffer[0] == '\0')
	{
		reade = read(fd, buffer, BUFFER_SIZE);
		buffer[reade] = '\0';
	}
	str = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!str)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && reade != 0)
	{
		str = ft_strjoin(str, buffer);
		reade = read(fd, buffer, BUFFER_SIZE);
		if (reade == -1)
			return (free(str), NULL);
		buffer[reade] = '\0';
	}
	str = ft_strjoin(str, buffer);
	return (str);
}

char	*line_to_buffer(char *str)
{
	size_t		i;
	char		*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	free(str);
	return (line);
}

void	read_next_line(char *line, char *buffer)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	j = 0;
	while (line[i])
		buffer[j++] = line[i++];
	buffer[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1] = {0};
	char			*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, buffer);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	read_next_line(line, buffer);
	line = line_to_buffer(line);
	return (line);
}

// #include <fcntl.h>

//  int main()
//  {
//  	char *buffer;
//  	int fd;

//  	fd = open("gnlTester/files/multiple_line_with_nl", O_RDWR);
//  	while ((buffer = get_next_line(fd)))
//  	{
//  		printf("%s", buffer);
// 		free(buffer);
//  	}
//  }

// int	main()
// {
// 	char	*line;
// 	int	fd;

// 	fd = open("testgnl", O_RDONLY);

// 	line = get_next_line(fd);
// 	printf("line : %s\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("line : %s\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("line : %s\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("line : %s\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("line : %s\n", line);
// 	line = get_next_line(fd);
// 	printf("line : %s\n", line);
// 	free(line);
// 	return (0);
// }
