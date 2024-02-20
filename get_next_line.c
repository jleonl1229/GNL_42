/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:50:57 by jleon-la          #+#    #+#             */
/*   Updated: 2024/02/20 18:37:11 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *length);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// char	*print_line(char *line)
// {
// 	size_t	i;
// 	size_t	flag = 0;
// 	size_t	j;
// 	char	*heap;
// 	size_t	z;
// 	size_t	h;

// 	i = 0;
// 	j = 0;
// 	z = 0;
// 	h = 0;
// 	while (line[i++]) // Cuento los \n del texto
// 	{
// 		if (line[i] == '\n')
// 			flag++;
// 	}
// 	i = 0;
// 	while (line[i]) // consigo el numero de caracteres que hay entre el ultimo \n y el final
// 	{
// 		while (j != flag)
// 		{
// 			if (line[i] == '\n')
// 				j++;
// 			i++;
// 		}
// 		z++;
// 		i++;
// 	}
// 	heap = malloc(sizeof(char) * z + 1);
// 	i = 0;
// 	j = 0;
// 	while (line[i]) // Consigo meter en mi malloc los caraceres en los margenes establecidos con la z
// 	{
// 		while (j != flag)
// 		{
// 			if (line[i] == '\n')
// 				j++;
// 			i++;
// 		}
// 		if (!heap)
// 			free(heap);
// 		heap[h] = line[i]; // POR HACER: Me falta poner un limite en el tramo anterior para que pare cuando se encuentre otro \n o el \0 y tambien que el flag sume 1 por cada vez que se entra a la funcion para asi poder ir avanzando por el string e ir haciendo next line
// 		h++;
// 		i++;
// 	}
// 	return (heap); // Devuelvo el string que corresponde a la linea
// }

char	*get_leftover(char *line)
{
	char	*leftover;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[i++])
	{
		if (line[i] == '\n')
		{
			i++;
			break ;
		}
	}
	leftover = malloc(sizeof(char) * i - ft_strlen(line) + 1);
	while (line[i])
	{
		leftover[j] = line[i];
		j++;
		i++;
	}
	return (leftover);
}

char	*cut_print(char *line)
{
	char	*cut;
	size_t	i;
	size_t	j;
	size_t	z;

	i = 0;
	j = 0;
	z = 0;
	while (line[i++])
	{
		if (line[i] == '\n')
		{
			i++;
			break ;
		}
	}
	cut = malloc(sizeof(char) * i + 1);
	while (z <= i)
	{
		cut[j] = line[z];
		j++;
		z++;
	}
	return (cut);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*save = "";
	char		*line;
	size_t		bytes_read;

	line = malloc (sizeof(char) * 1);
	line[0] = '\0';
	while (!ft_strchr(line, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	// Tengo que separar esta funcion en el sobrante(caracteres de despues de \n) y lo que se imprimirá en esta linea (antes de \n)
	save = get_leftover(line);
	return (cut_print(line));
}

int	main(void)
{
	int	fd;

	fd = open("archivo.txt", O_RDONLY);
	if (fd == -1)
		printf("Error on opening the file");
	printf("%s", get_next_line(fd));
	return (0);
}
