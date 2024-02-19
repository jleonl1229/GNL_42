/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:50:57 by jleon-la          #+#    #+#             */
/*   Updated: 2024/02/19 12:08:40 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *length);
char	*ft_strjoin(char const *s1, char const *s2);

char	*print_line(char *line)
{
	size_t	i;
	size_t	flag;
	size_t	j;
	char	*heap;
	size_t	z;
	size_t	h;

	i = 0;
	flag = 0;
	j = 0;
	z = 0;
	h = 0;
	while (line[i++])
	{
		if (line[i] == '\n')
			flag++;
	}
	i = 0;
	while (line[i])
	{
		while (j != flag)
		{
			if (line[i] == '\n')
				j++;
			i++;
		}
		z++;
		i++;
	}
	heap = malloc(sizeof(char) * z + 1);
	i = 0;
	j = 0;
	while (line[i])
	{
		while (j != flag)
		{
			if (line[i] == '\n')
				j++;
			i++;
		}
		heap[h] = line[i];
		h++;
		i++;
	}
	return (heap);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*save;
	size_t		bytes_read;

	save = ft_strdup("");
	while (!ft_strchr(line, '\n') || !ft_strchr(line, '\0'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		// if (bytes_read == -1)
		// 	write(1, "Error on reading", 16);
		// else if (bytes_read == 0)
		// 	write(1, "Nothing to read", 15);
		buffer[bytes_read] = '\0';
		line = ft_strjoin(save, buffer);
		if (!line)
			return (NULL);
	}
	return (print_line(line));
}

int	main(void)
{
	int	fd;

	fd = open("archivo.txt", O_RDONLY);
	if (fd == -1)
		printf("Error on opening the file");
	else
		printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	return (0);
}
