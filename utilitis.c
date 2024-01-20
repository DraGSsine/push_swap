/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:04:14 by youchen           #+#    #+#             */
/*   Updated: 2024/01/20 08:28:51 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_free(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		free(s[i++]);
	free(s);
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

int	is_still_chunk_values(t_list *stack, size_t chunk_values)
{
	size_t	i;

	i = 0;
	while (stack)
	{
		if (stack->position < chunk_values)
			return (1);
		stack = stack->next;
	}
	return (0);
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
