/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitis2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:03:18 by youchen           #+#    #+#             */
/*   Updated: 2024/01/18 14:04:01 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current_node;
	int		i;

	i = 0;
	current_node = lst;
	while (current_node)
	{
		i++;
		current_node = current_node->next;
	}
	return (i);
}

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
