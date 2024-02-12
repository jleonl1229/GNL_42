/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:50:57 by jleon-la          #+#    #+#             */
/*   Updated: 2024/02/12 16:39:28 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	str[BUFFER_SIZE];
	char	*str2;
	size_t	bytes_read;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	bytes_read = read(fd, str, BUFFER_SIZE);
	str2 = malloc(sizeof(char) * bytes_read);
	while (str[i])
		str2[j++] = str[i++];
	return (str2);
}

int	main(void)
{
	int	fd;

	fd = open("archivo.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}
