/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 17:46:44 by maoulad           #+#    #+#             */
/*   Updated: 2026/10/27 16:22:53 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_get(int fd, char *chunk)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(chunk, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= -1)
		{
			free(buffer);
			free(chunk);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		chunk = ft_strjoin(chunk, buffer);
	}
	free(buffer);
	return (chunk);
}

char	*get_line(char *chunk)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!chunk[i])
		return (NULL);
	while (chunk[i] && chunk[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (chunk[i] && chunk[i] != '\n')
	{
		str[i] = chunk[i];
		i++;
	}
	if (chunk[i] == '\n')
	{
		str[i] = chunk[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*go_to_next_chunk(char *chunk)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (chunk[i] && chunk[i] != '\n')
		i++;
	if (!chunk[i])
	{
		free(chunk);
		return (NULL);
	}
	str = (char *)malloc(ft_strlen(chunk) - i + 1);
	if (!str)
	{
		free(chunk);
		return (NULL);
	}
	i++;
	j = 0;
	while (chunk[i])
		str[j++] = chunk[i++];
	str[j] = '\0';
	free(chunk);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*chunks[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	chunks[fd] = read_and_get(fd, chunks[fd]);
	if (!chunks[fd])
		return (NULL);
	line = get_line(chunks[fd]);
	if (!line)
	{
		free(chunks[fd]);
		chunks[fd] = NULL;
		return (NULL);
	}
	chunks[fd] = go_to_next_chunk(chunks[fd]);
	return (line);
}
