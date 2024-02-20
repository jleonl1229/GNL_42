/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:50:24 by jleon-la          #+#    #+#             */
/*   Updated: 2024/02/19 15:03:03 by jleon-la         ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (s[l])
	{
		l++;
	}
	while (i <= l)
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*memory;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((!s1 || s1 == NULL) || (!s2 || s2 == NULL))
		return (NULL);
	memory = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!memory)
		return (NULL);
	while (s1[i] && s1[i] != '\0')
	{
		memory[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\0')
	{
		memory[i] = s2[j];
		i++;
		j++;
	}
	memory[i] = '\0';
	return (memory);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*memory;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || start < 0 || len < 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	while (i < start)
		i++;
	memory = malloc(sizeof(char) * (len + 1));
	if (!memory)
		return (NULL);
	while (s && len && j < len)
	{
		memory[j] = s[i];
		i++;
		j++;
	}
	memory[j] = '\0';
	return (memory);
}
