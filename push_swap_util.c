/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:23:48 by youchen           #+#    #+#             */
/*   Updated: 2024/01/13 21:36:10 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_node(t_list **head_ref, size_t key)
{
	t_list *temp = *head_ref;
	t_list *prev = NULL;

	if (temp->position == key)
	{
		*head_ref = temp->next;
		free(temp);
		return ;
	}

	while (temp->position != key)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	free(temp);
}

int sorted(t_list *stack)
{
	t_list *current = stack;

	while (current)
	{
		if (current->next && current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}

void stort_three_numbers(t_list **stack)
{
	if ((*stack)->number > (*stack)->next->number)
	{
		swap_a(stack);
		if (sorted(*stack))
			return;
	}
	if ((*stack)->next->number > (*stack)->next->next->number)
	{
		reverse_rotate_a(stack);
		if (sorted(*stack))
			return ;
	}
	swap_a(stack);
}

void	sort_four_numbers(t_list **stack_a, t_list **stack_b)
{
	t_list *current = *stack_a;

	while (current)
	{
		if (current->position == 0)
		{
			ft_lstadd_back(stack_b, ft_lstnew(current->number, *stack_b));
			remove_node(stack_a, current->position);
			break ;
		}
		current = current->next;
	}
	stort_three_numbers(stack_a);
	ft_lstadd_front(stack_a, *stack_b);
}

void	sort_five_numbers(t_list **stack_a, t_list **stack_b)
{
	t_list *current = *stack_a;

	while (current)
	{
		if (current->position == 0)
		{
			ft_lstadd_back(stack_b, ft_lstnew(current->number, *stack_b));
			remove_node(stack_a, current->position);
			break ;
		}
		current = current->next;
	}
	current = *stack_a;
	while (current)
	{
		if (current->position == 1)
		{
			ft_lstadd_back(stack_b, ft_lstnew(current->number, *stack_b));
			remove_node(stack_a, current->position);
			break ;
		}
		current = current->next;
	}
	stort_three_numbers(stack_a);
	ft_lstcat(stack_a, stack_b);
}
