/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:05:02 by youchen           #+#    #+#             */
/*   Updated: 2024/01/25 14:07:27 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *buff)
{
	char	*ptr_str;
	size_t	i;
	size_t	x;

	i = -1;
	x = 0;
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!buff)
		return (NULL);
	ptr_str = malloc(ft_strlen(s1) + ft_strlen(buff) + 1);
	if (!ptr_str)
		return (free(s1), NULL);
	while (++i < (size_t)ft_strlen(s1))
		ptr_str[i] = s1[i];
	while (x < (size_t)ft_strlen(buff))
		ptr_str[i++] = buff[x++];
	ptr_str[i] = '\0';
	return (free(s1), ptr_str);
}
