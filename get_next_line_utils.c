/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:00:26 by pnolte            #+#    #+#             */
/*   Updated: 2022/05/04 16:36:51 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c, int byte_read)
{
	char			*p;
	unsigned char	a;
	int				i;

	i = 0;
	a = (unsigned char)c;
	p = (char *)str;
	if (i == byte_read - 1)
		return (NULL);
	while (p[i] != a)
	{
		if (i == byte_read)
		{
			return (NULL);
		}
		i++;
	}
	return (p);
}

char	*ft_strjoin(char *s1, char *s2, int byte_read)
{
	char	*p;
	int		j;
	int		size;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + byte_read + 1;
	p = malloc(sizeof(char) * size);
	if (p == NULL)
		return (NULL);
	size = 0;
	j = 0;
	while (s1[j] != '\0')
		p[size++] = s1[j++];
	j = 0;
	while (j < byte_read)
		p[size++] = s2[j++];
	p[size] = '\0';
	free(s1);
	return (p);
}

int	ft_strlen(const char *c)
{
	int	index;

	index = 0;
	while (c[index] != '\0')
		index++;
	return (index);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*d;

	if (s == NULL)
		return (NULL);
	if (len >= start)
	{
		len = len - start;
		d = malloc((len + 1) * sizeof(char));
		if (d == NULL)
			return (NULL);
		i = 0;
		while (s[start] != '\0' && i < len)
			d[i++] = s[start++];
		d[len] = '\0';
		free(s);
		return (d);
	}
	else
	{
		free(s);
		return (NULL);
	}
}
