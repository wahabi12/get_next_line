/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 03:51:41 by blatifat          #+#    #+#             */
/*   Updated: 2023/12/04 18:54:02 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

char	*get_line_l(char *buffer, char *line)
{
	char	*temp;
	char	*temp_join;
	int		i;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	if (i > 0 && !line)
	{
		line = ft_substr(buffer, 0, i + 1);
		return (ft_strcpy(buffer, buffer + i + 1), line);
	}
	else if (i > 0)
	{
		temp = ft_substr(buffer, 0, i + 1);
		temp_join = concat_line(line, temp);
		free(temp);
		return (ft_strcpy(buffer, buffer + i + 1), temp_join);
	}
	else if (i == 0 && line)
	{
		return (ft_strcpy(buffer, buffer + i + 1), concat_line(line, "\n"));
	}
	return (ft_strcpy(buffer, buffer + i + 1), ft_strdup("\n"));
}

char	*concat_line(char *line, char *str)
{
	char	*temp;

	if (line == NULL)
		line = ft_strdup(str);
	else
	{
		temp = ft_strjoin(line, str);
		free(line);
		line = temp;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			byte_read;
	char		*line;

	if (fd < 0 && buffer <= 0)
		return (NULL);
	line = NULL;
	if (ft_strchr(buffer, '\n'))
		return (get_line_l(buffer, line));
	if (buffer[0] != '\0')
		line = ft_strdup(buffer);
	while (1)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
			return (free(line), buffer[0] = 0, NULL);
		if (byte_read == 0 && !ft_strchr(buffer, '\n'))
			return (buffer[0] = 0, line);
		buffer[byte_read] = '\0';
		if (ft_strchr(buffer, '\n'))
			return (get_line_l(buffer, line));
		line = concat_line(line, buffer);
	}
}
