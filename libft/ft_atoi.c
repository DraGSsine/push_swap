/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:54:49 by youchen           #+#    #+#             */
/*   Updated: 2024/01/21 08:04:17 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_minus(const char *s)
{
	int	i;
	int	minus;

	i = -1;
	minus = 0;
	while (s[++i])
	{
		if (s[i] == '-')
			minus++;
	}
	if (minus == 1 && s[0] != '-')
		ft_error();
	return (minus);
}

int	count_plus(const char *s)
{
	int	i;
	int	plus;

	i = -1;
	plus = 0;
	while (s[++i])
	{
		if (s[i] == '+')
			plus++;
	}
	if (plus == 1 && s[0] != '+')
		ft_error();
	return (plus);
}

int	ft_str_is_numeric(const char *s)
{
	int	i;

	i = 0;
	if (count_minus(s) > 1 || count_plus(s) > 1)
		ft_error();
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9') || (s[i] == '+' || s[i] == '-' ))
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	long int	sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!ft_str_is_numeric(nptr) || *nptr == '\0')
		ft_error();
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign *= -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + nptr[i++] - '0';
	result *= sign;
	if (result < INT_MIN || result > INT_MAX)
		ft_error();
	return (result);
}
