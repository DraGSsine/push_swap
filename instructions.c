/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:21:09 by youchen           #+#    #+#             */
/*   Updated: 2024/01/14 17:23:17 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_list **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return ;
	t_list *temp1 = *stack;
	t_list *temp2 = (*stack)->next;
	temp1->next = temp2->next;
	temp2->next = temp1;

	*stack = temp2;
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list *temp;

	if (!stack_a || !*stack_a || !stack_b)
		return ;

	temp = *stack_a;
	*stack_a = (*stack_a)->next;

	temp->next = *stack_b;
	*stack_b = temp;
}

void rotate_a(t_list **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return ;
	t_list *temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;

	ft_lstadd_back(stack, temp);
}
void reverse_rotate_a(t_list **stack)
{
    if (!stack || !*stack || !(*stack)->next)
        return;

    t_list *last_element = *stack;
    t_list *previous_element = NULL;

    while (last_element->next)
    {
        previous_element = last_element;
        last_element = last_element->next;
    }
    previous_element->next = NULL;
    ft_lstadd_front(stack, last_element);
}

