/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:34:15 by youchen           #+#    #+#             */
/*   Updated: 2024/01/22 08:12:16 by youchen          ###   ########.fr       */
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
		exit(0);
	else if (ac == 2)
	{
		nums = ft_split(av[1], ' ');
		while (nums[++j])
			ft_atoi(nums[j]);
	}
	else
	{
		while (++i < ac)
			ft_atoi(av[i]);
		nums = av + 1;
	}
	return (nums);
}
