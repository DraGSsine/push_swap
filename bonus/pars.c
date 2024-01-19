/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:34:15 by youchen           #+#    #+#             */
/*   Updated: 2024/01/19 21:02:47 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**parse(int ac, char **av)
{
	char	**nums;
	int		i;
	int		j;

	j = -1;
	i = 0;
	if (ac == 1)
		exit(1);
	else if (ac == 2)
	{
		nums = ft_split(av[1], ' ');
		while (nums[++j])
			if (!(ft_atoi(nums[j]) >= INT_MIN && ft_atoi(nums[j]) <= INT_MAX))
				ft_error();
	}
	else
	{
		while (++i < ac)
			if (!(ft_atoi(av[i]) >= INT_MIN && ft_atoi(av[i]) <= INT_MAX))
				ft_error();
		nums = av + 1;
	}
	return (nums);
}
