/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:47:59 by youchen           #+#    #+#             */
/*   Updated: 2024/01/20 09:02:33 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(const char *str, char sp)
{
	size_t	nb_strings;

	nb_strings = 0;
	while (*str)
	{
		if (*str != sp)
		{
			while (*str != '\0' && *str != sp)
				str++;
			nb_strings++;
		}
		if (*str)
			str++;
	}
	if (ft_strlen(str) == 1)
		nb_strings = 1;
	return (nb_strings);
}

static const char	*charcopy_until_char(char **dest, const char *src, char c)
{
	const char	*start;
	size_t		len;
	char		*d;
	const char	*s;

	len = 0;
	while (*src == c)
		src++;
	start = src;
	while (*src && *src != c)
		src++;
	len = src - start;
	*dest = malloc(len + 1);
	if (!*dest)
		return (NULL);
	d = *dest;
	s = start;
	while (s < src)
	{
		*d++ = *s++;
	}
	*d = '\0';
	return (src);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	size_t	nb_strings;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	nb_strings = count_words(s, c);
	strs = malloc((nb_strings + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	strs[nb_strings] = NULL;
	while (i < nb_strings)
	{
		s = charcopy_until_char(strs + i, s, c);
		if (!s)
		{
			while (i > 0)
				free(strs[--i]);
			free(strs);
			return (NULL);
		}
		i++;
	}
	return (strs);
}
