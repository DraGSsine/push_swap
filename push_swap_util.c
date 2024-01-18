/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:23:48 by youchen           #+#    #+#             */
/*   Updated: 2024/01/18 14:04:50 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stort_three_numbers(t_list **stack)
{
	if ((*stack)->number > (*stack)->next->number)
	{
		swap_stack(stack, "sa");
		if (sorted(*stack))
			return ;
	}
	if ((*stack)->next->number > (*stack)->next->next->number)
	{
		reverse_rotate_stack(stack, "rra");
		if (sorted(*stack))
			return ;
	}
	swap_stack(stack, "sa");
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
	while ((*stack_a) && (*stack_a)->position != 0)
	{
		rotate_stack(stack_a, "ra");
	}
	push_stack(stack_a, stack_b, "pb");
	while ((*stack_a) && (*stack_a)->position != 1)
	{
		rotate_stack(stack_a, "ra");
	}
	push_stack(stack_a, stack_b, "pb");
	stort_three_numbers(stack_a);
	push_stack(stack_b, stack_a, "pa");
	push_stack(stack_b, stack_a, "pa");
}
