/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:50:57 by jleon-la          #+#    #+#             */
/*   Updated: 2024/02/16 16:01:45 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *length);

char	*get_line(char *line)
{
	
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*save;
	size_t		bytes_read;

	save = ft_strdup("");
	while (!ft_strchr(line, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			write(1, "Error on reading", 16);
		buffer[bytes_read] = '\0';
		line = ft_strjoin(save, buffer);
		if (!line)
			return (NULL);
	}
	return (get_line(line));
}

int	main(void)
{
	int	fd;

	fd = open("archivo.txt", O_RDONLY);
	if (get_next_line(fd) == -1)
		printf("Error on opening the file");
	else
		printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	return (0);
}
