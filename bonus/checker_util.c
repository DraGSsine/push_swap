/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:15:16 by youchen           #+#    #+#             */
/*   Updated: 2024/01/21 10:00:24 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

int	sorted(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current)
	{
		if (current->next && current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		x;

	i = 0;
	x = -1;
	while (s1[++x])
		if (s1[x] == 9 || (s1[x] > 10 && s1[x] <= 32))
			ft_error();
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	check_dublicat(t_list **stack_a)
{
	t_list	*current;
	t_list	*nested_current;

	current = *stack_a;
	while (current)
	{
		nested_current = current->next;
		while (nested_current)
		{
			if (current->number == nested_current->number)
				ft_error();
			nested_current = nested_current->next;
		}
		current = current->next;
	}
	return ;
}
