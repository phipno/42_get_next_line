/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:00:22 by pnolte            #+#    #+#             */
/*   Updated: 2022/05/04 16:39:02 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *remember, int fd)
{
	char	buffer[BUFFER_SIZE];
	int		byte_read;

	byte_read = 1;
	while (byte_read != 0 && (!ft_strchr(buffer, '\n', byte_read)))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
			return (NULL);
		remember = ft_strjoin(remember, buffer, byte_read);
	}
	return (remember);
}

char	*ft_cut(char *remember)
{
	char	*new_line;
	int		i;

	i = 0;
	if (remember == NULL || remember[0] == '\0')
		return (NULL);
	while (remember[i] != '\0' && remember[i] != '\n')
		i++;
	if (ft_strchr(remember, '\n', ft_strlen(remember)))
		new_line = malloc(sizeof(char) * (i + 2));
	else
		new_line = malloc(sizeof(char) * (i + 1));
	if (new_line == NULL)
		return (NULL);
	i = 0;
	while (remember[i] != '\n' && remember[i] != '\0')
	{
		new_line[i] = remember[i];
		i++;
	}
	if (remember[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*remember;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remember = ft_read(remember, fd);
	if (remember == NULL)
		return (NULL);
	line = ft_cut(remember);
	i = 0;
	while (remember[i] != '\n' && remember[i] != '\0')
		i++;
	remember = ft_substr(remember, i + 1, ft_strlen(remember));
	return (line);
}

// void check_leaks();

// int main(void)
// {
// 	int i;
// 	char *p;

// 	p = NULL;
// 	i = open("multiple_line_no_nl", O_RDONLY);
// 	p = get_next_line(i);
// 	printf("Result:%s\n", p);
// 	free(p);
// 	p = get_next_line(i);
// 	printf("Result:%s\n", p);
// 	free(p);
// 	p = get_next_line(i);
// 	printf("Result:%s\n", p);
// 	free(p);
// 	p = get_next_line(i);
// 	printf("Result:%s\n", p);
// 	free(p);
// 	p = get_next_line(i);
// 	printf("Result:%s\n", p);
// 	free(p);
// 	p = get_next_line(i);
// 	printf("Result:%s\n", p);
// 	free(p);
// 	check_leaks();
// 	return (0);
// }
