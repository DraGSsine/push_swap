/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:21:09 by youchen           #+#    #+#             */
/*   Updated: 2024/01/29 12:08:17 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_stack(t_list **stack)
{
	t_list	*temp1;
	t_list	*temp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp1 = *stack;
	temp2 = (*stack)->next;
	temp1->next = temp2->next;
	temp2->next = temp1;
	*stack = temp2;
}

void	push_stack(t_list **from, t_list **to)
{
	t_list	*temp;

	if (!from || !*from || !to)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
}

void	rotate_stack(t_list **stack)
{
	t_list	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
}

void	reverse_rotate_stack(t_list **stack)
{
	t_list	*last_element;
	t_list	*previous_element;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last_element = *stack;
	previous_element = NULL;
	while (last_element->next)
	{
		previous_element = last_element;
		last_element = last_element->next;
	}
	previous_element->next = NULL;
	ft_lstadd_front(stack, last_element);
}
