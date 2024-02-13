/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:50:24 by jleon-la          #+#    #+#             */
/*   Updated: 2024/02/13 12:56:46 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// join(pero modificarlo para que busque no solo hasta \0 sino tambien hasta \n) memcpopy strlen 

size_t	ft_strlen(const char *length)
{
	int	i;

	i = 0;
	while (length[i] && length[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t		i;
	char		*memory;

	memory = malloc((ft_strlen(s1) + 1) * sizeof(char));
	i = 0;
	if (!memory)
		return (0);
	while (i < ft_strlen(s1))
	{
		memory[i] = s1[i];
		i++;
	}
	memory[i] = '\0';
	return (memory);
}
