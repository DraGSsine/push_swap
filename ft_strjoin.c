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

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *buff)
{
	t_data	data;

	data.i = -1;
	data.x = 0;
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!buff)
		return (NULL);
	data.s1_len = ft_strlen(s1);
	data.s2_len = ft_strlen(buff);
	data.ptr_str = malloc(data.s1_len + data.s2_len + 2);
	if (!data.ptr_str)
		return (free(s1), NULL);
	while (++data.i < data.s1_len)
		data.ptr_str[data.i] = s1[data.i];
	while (data.x < data.s2_len + 1)
		data.ptr_str[data.i++] = buff[data.x++];
	data.ptr_str[data.i - 1] = ' ';
	data.ptr_str[data.i] = '\0';
	return (free(s1), data.ptr_str);
}
