/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:23:48 by youchen           #+#    #+#             */
/*   Updated: 2024/01/22 07:40:12 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stort_three_numbers(t_list **stack)
{
	if (sorted(*stack))
		return ;
	if ((*stack)->number < (*stack)->next->number)
	{
		reverse_rotate_stack(stack, "rra");
		if (sorted(*stack))
			return ;
		swap_stack(stack, "sa");
	}
	else
	{
		if ((*stack)->number < (*stack)->next->next->number)
			swap_stack(stack, "sa");
		else
		{
			rotate_stack(stack, "ra");
			if (!sorted(*stack))
				swap_stack(stack, "sa");
		}
	}
}

void	sort_four_numbers(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a) && (*stack_a)->position != 0)
	{
		rotate_stack(stack_a, "ra");
	}
	push_stack(stack_a, stack_b, "pb");
	stort_three_numbers(stack_a);
	push_stack(stack_b, stack_a, "pa");
}

void	sort_five_numbers(t_list **stack_a, t_list **stack_b)
{
	t_node_at	zero;
	t_node_at	one;

	zero = found_node_at(stack_a, 0);
	one = found_node_at(stack_a, 1);
	take_node_to_toop(stack_a, zero, "rra", "ra");
	push_stack(stack_a, stack_b, "pb");
	take_node_to_toop(stack_a, one, "rra", "ra");
	push_stack(stack_a, stack_b, "pb");
	stort_three_numbers(stack_a);
	push_stack(stack_b, stack_a, "pa");
	push_stack(stack_b, stack_a, "pa");
}

void	sort_large_numbers(t_list **stack_a, t_list **stack_b, size_t list_size)
{
	size_t	chunk;
	size_t	div;

	div = 5;
	if (list_size > 200)
		div = 10;
	chunk = list_size / div;
	while ((*stack_a))
	{
		while ((*stack_a)->position >= chunk)
			rotate_stack(stack_a, "ra");
		while ((*stack_a) && (*stack_a)->position < chunk)
		{
			if ((*stack_a)->position < chunk - ((list_size / div) / 2))
				push_stack(stack_a, stack_b, "pb");
			else
			{
				push_stack(stack_a, stack_b, "pb");
				rotate_stack(stack_b, "rb");
			}
		}
		if (!is_still_chunk_values(*stack_a, chunk))
			chunk += (list_size / div);
	}
}

void	sort(t_list **stack_a, t_list **stack_b, size_t list_size)
{
	if (list_size == 2)
		swap_stack(stack_a, "sa");
	else if (list_size == 3)
		stort_three_numbers(stack_a);
	else if (list_size == 4)
		sort_four_numbers(stack_a, stack_b);
	else if (list_size == 5)
		sort_five_numbers(stack_a, stack_b);
	else
	{
		sort_large_numbers(stack_a, stack_b, list_size);
		push_back_to_a(stack_a, stack_b);
	}
}
