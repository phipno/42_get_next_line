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

char	*ft_strchr(const char *str, int c)
{
	char			*p;
	unsigned char	a;

	a = (unsigned char)c;
	p = (char *)str;
	while (*p != a)
	{
		if (*p == '\0')
			return (NULL);
		p++;
	}
	return (p);
}

char	*ft_strjoin(char *s1, char *s2, int byte_read)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	if (s1 == NULL)
	{
		printf("hi");
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = ft_strlen(s1) + byte_read;
	p = malloc(sizeof(char) * (j + 1));
	if (p == NULL)
		return (NULL);
	while (*s1 != '\0')
		p[i++] = *s1++;
	while (i < j)
		p[i++] = *s2++;
	p[i] = '\0';
	// free(s1);
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

static unsigned int	new_length(unsigned int s_len, unsigned int s, size_t len)
{
	unsigned int	new_len;

	if (s >= len)
		new_len = 0;
	if (s >= s_len)
		new_len = 0;
	else if (s_len >= len)
		new_len = len;
	else if (len > s_len)
		new_len = s_len;
	return (new_len);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	s_len;
	char			*d;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	len = new_length(s_len, start, len);
	d = malloc((len + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		d[i] = s[start];
		i++;
		start++;
	}
	d[len] = '\0';
	free(s);
	return (d);
}
