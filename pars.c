/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:34:15 by youchen           #+#    #+#             */
/*   Updated: 2024/01/22 08:00:18 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *buff)
{
	char	*ptr_str;
	int		i;
	int		x;

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
	while (++i < ft_strlen(s1))
		ptr_str[i] = s1[i];
	while (x < ft_strlen(buff))
		ptr_str[i++] = buff[x++];
	ptr_str[i] = '\0';
	return (free(s1), ptr_str);
}

char	**parse(int ac, char **av)
{
	int		i;
	int		j;
	char	*nums_as_strings;
	char	**nums;

	j = -1;
	i = 1;
	nums_as_strings = NULL;
	if (ac == 1)
		exit(0);
	while (av[i])
	{
		if (ft_strlen(av[1]) == 0)
			exit(0);
		if (ft_strlen(av[i]) == 0)
			ft_error();
		nums_as_strings = ft_strjoin(nums_as_strings, " ");
		nums_as_strings = ft_strjoin(nums_as_strings, av[i++]);
	}
	nums = ft_split(nums_as_strings, ' ');
	free(nums_as_strings);
	return (nums);
}
