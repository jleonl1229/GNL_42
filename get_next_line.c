/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:50:57 by jleon-la          #+#    #+#             */
/*   Updated: 2024/02/13 12:31:13 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *length);

char	*get_next_line(int fd)
{
	char	str[BUFFER_SIZE + 1];
	char	*str2;
	size_t	bytes_read;

	bytes_read = read(fd, str, BUFFER_SIZE);
	str2 = ft_strdup(str);
	return (str2);
}

int	main(void)
{
	int	fd;

	fd = open("archivo.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}
