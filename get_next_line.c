/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:50:57 by jleon-la          #+#    #+#             */
/*   Updated: 2024/02/26 15:17:08 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *length);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*get_leftover(char *line)
{
	char	*leftover;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	// printf("-->FULL_Line:%s\n", line);
	while (line[i++])
	{
		if (line[i] == '\n')
			break ;
	}
	leftover = malloc(((ft_strlen(line) + 1) - i) * sizeof(char));
	if (!leftover)
		return (NULL);
	while (line[i])
		leftover[j++] = line[i++];
	// printf("-->Leftover:%s\n", leftover);
	return (leftover);
}

char	*cut_print(char *line)
{
	char	*cut;
	int		i;
	int		j;
	int		z;

	i = 0;
	j = 0;
	z = 0;
	while (line[i++])
	{
		if (line[i] == '\n')
			break ;
	}
	cut = malloc(sizeof(char) * (i + 1));
	if (!cut)
		return (NULL);
	while (z < i)
		cut[j++] = line[z++];
	cut[j] = '\0';
	// printf("-->CLEAN_Line:%s\n", cut);
	return (cut);
}

// char	*get_next_line(int fd)
// {
// 	static char	buffer[BUFFER_SIZE + 1];
// 	static char	*save = "";
// 	char		*line;
// 	size_t		bytes_read;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	line = malloc (sizeof(char) * 1);
// 	line[0] = '\0';
// 	if (ft_strlen(save) >= 1)
// 		line = ft_strjoin(line, save);
// 	while (!ft_strchr(line, '\n'))
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read <= 0)
// 			return (NULL);
// 		buffer[bytes_read] = '\0';
// 		line = ft_strjoin(line, buffer);
// 	}
// 	save = get_leftover(line);
// 	// printf("%s", save);
// 	return (cut_print(line));
// }

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*save = "";
	// printf("save:%s\n", save);
	char		*line;
	size_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	if (ft_strlen(save) >= 1)
		line = ft_strjoin(line, save);
	while (!ft_strchr(line, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	save = get_leftover(line);
	// printf("%s", save);
	return (cut_print(line));
}

int	main(void)
{
	int	fd;

	fd = open("archivo.txt", O_RDONLY);
	if (fd == -1)
		printf("Error on opening the file");
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("Original: %s\n", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	return (0);
}
