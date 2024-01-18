/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:21:09 by youchen           #+#    #+#             */
/*   Updated: 2024/01/18 14:20:54 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list **stack, char *instraction)
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
	printf("%s\n", instraction);
}

void	push_stack(t_list **from, t_list **to, char *instraction)
{
	t_list	*temp;

	if (!from || !*from || !to)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
	printf("%s\n", instraction);
}

void	rotate_stack(t_list **stack, char *instraction)
{
	t_list	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
	printf("%s\n", instraction);
}

void	reverse_rotate_stack(t_list **stack, char *instraction)
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
	printf("%s\n", instraction);
}
