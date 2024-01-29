/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:39:23 by youchen           #+#    #+#             */
/*   Updated: 2024/01/29 12:08:21 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_left_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (ft_substr(str, ++i, ft_strlen(str)));
}

char	*get_the_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (ft_substr(str, 0, ++i));
}

char	*read_and_process_buffer(int fd, char *left)
{
	char	*buffer;
	int		r;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	r = read(fd, buffer, BUFFER_SIZE);
	while (r > 0)
	{
		buffer[r] = '\0';
		left = ft_strjoin(left, buffer);
		if (!left)
			return (free(buffer), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
		r = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (r == -1)
	{
		free(left);
		left = NULL;
		return (NULL);
	}
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;
	char		*ret;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	left = read_and_process_buffer(fd, left);
	if (!left)
		return (NULL);
	if (ft_strchr(left, '\n'))
	{
		line = get_the_line(left);
		ret = get_left_string(left);
		return (free(left), left = NULL, left = ret, line);
	}
	if (*left)
	{
		line = ft_strjoin(line, left);
		return (free(left), left = NULL, line);
		return (left);
	}
	return (free(left), left = NULL, NULL);
}
