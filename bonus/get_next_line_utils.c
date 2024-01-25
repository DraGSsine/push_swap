/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:26:19 by youchen           #+#    #+#             */
/*   Updated: 2024/01/25 14:04:55 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s1)
{
	int	i;

	i = 0;
	if (s1 == NULL)
		return (0);
	while (s1[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*ptr_str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
	{
		ptr_str = malloc(1);
		if (!ptr_str)
			return (NULL);
		ptr_str[0] = '\0';
		return (ptr_str);
	}
	if (start + len > s_len)
		len = s_len - start;
	ptr_str = malloc(len + 1);
	if (ptr_str == NULL)
		return (NULL);
	while (i < len)
		ptr_str[i++] = s[start++];
	ptr_str[len] = '\0';
	return (ptr_str);
}

int	ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	if (*s == (char)c)
		return (1);
	return (0);
}
