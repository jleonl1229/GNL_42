/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:50:57 by jleon-la          #+#    #+#             */
/*   Updated: 2024/02/28 19:35:22 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_leftover(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')// Contamos caracteres hasta el \0 o el \n
		i ++;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	if (!buffer[i])// Si hay problemas nos saca de la función
	{
		ft_bzero(&buffer[j], BUFFER_SIZE - j);
		return ;
	}
	while (buffer[i + j])// Copio el leftover en line[j]
	{
		buffer[j] = buffer[i + j];
		j++;
	}
	ft_bzero(&buffer[j], BUFFER_SIZE - j);// Formateo el contenido de las direcciones de memoria a 0
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * 1); // Inicializo line
	if (!line)
		return (free(line), NULL);
	line[0] = '\0';
	if (ft_strlen(buffer) >= 1)//Por si queda algo en el buffer
		line = ft_strjoin(line, buffer);
	while (!ft_strchr(buffer, '\n'))// Mientras no haya \n en el contenido del buffer me lees y joineas
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(line), NULL);
		buffer[bytes_read] = '\0';
		if (bytes_read <= 0)
			return (ft_bzero(buffer, ft_strlen(buffer)), line);
		line = ft_strjoin(line, buffer);
		// printf("quelee:%s", line);
		// printf("quebuff:%s", buffer);
	}
	get_leftover(buffer);
	// printf("quebuff2::%s", buffer);
	return (line);// Me devuelves line pdespués de pasarle el contenido original y quitarle el leftover
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("archivo.txt", O_RDONLY); //Abro el archivo y lo cargo en el file descriptor
// 	if (fd == -1)
// 		printf("Error on opening the file");
// 	printf("LINEA1=>%s", get_next_line(fd));
// 	printf("LINEA2=>%s", get_next_line(fd));
// 	printf("LINEA3=>%s", get_next_line(fd));
// 	printf("LINEA4=>%s", get_next_line(fd));
// 	printf("LINEA5=>%s", get_next_line(fd));
// 	printf("LINEA6=>%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	return (0);
// }
