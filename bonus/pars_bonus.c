/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:34:15 by youchen           #+#    #+#             */
/*   Updated: 2024/01/29 12:17:16 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	symbol_position(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
		{
			if ((s[i - 1] && s[i - 1] != ' ')
				|| !(s[i + 1] >= '0' && s[i + 1] <= '9'))
				return (1);
		}
		i++;
	}
	return (0);
}

int	count_smbols(char *s)
{
	int	i;
	int	plus;
	int	minus;

	i = -1;
	plus = 0;
	minus = 0;
	while (s[++i])
	{
		if (s[i] == '+')
			plus++;
		else if (s[i] == '-')
			minus++;
	}
	if (minus > 0 || plus > 0)
		if (symbol_position(s))
			ft_error();
	return (0);
}

int	no_int(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_str_is_numeric(char *s)
{
	int	i;

	i = 0;
	if (count_smbols(s) || !no_int(s))
		ft_error();
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9')
			|| (s[i] == '+' || s[i] == '-'
				|| s[i] == 32 || (s[i] >= 9 && s[i] <= 13)))
			i++;
		else
			return (0);
	}
	return (1);
}

char	**pars(int ac, char **av)
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
		if (!ft_str_is_numeric(av[i]) || *av[i] == '\0')
			ft_error();
		nums_as_strings = ft_strjoin(nums_as_strings, av[i++]);
	}
	nums = ft_split(nums_as_strings, ' ');
	free(nums_as_strings);
	return (nums);
}
