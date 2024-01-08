/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:05:58 by youchen           #+#    #+#             */
/*   Updated: 2024/01/08 18:06:01 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atoip(const char *s, int i, int sign)
{
	unsigned long long	nb;
	int					digc;

	nb = 0;
	digc = 0;
	while (s[i] >= 48 && s[i] <= 57)
	{
		digc++;
		if (digc == 20)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		nb = nb * 10 + s[i++] - 48;
	}
	if (nb > LONG_MAX)
	{
		if (sign == -1)
			return (0);
		else
			return (-1);
	}
	return ((int)(nb * sign));
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] == 48)
		i++;
	result = atoip(nptr, i, sign);
	return (result);
}
