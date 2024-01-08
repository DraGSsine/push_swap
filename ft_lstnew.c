/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:06:39 by youchen           #+#    #+#             */
/*   Updated: 2024/01/08 18:06:48 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_pos(t_list *stack, t_list *rtn)
{
	// t_list *current = stack;

	while (stack && rtn)
	{
		if(rtn->number > stack->number)
			(rtn->number)++;
		else
			stack->number++;
		stack = stack->next;
	}
}
t_list	*ft_lstnew(int content,t_list *stack_a)
{
	t_list	*rtn;

	(void)stack_a;
	rtn = malloc(sizeof(t_list));
	if (!rtn)
		return (NULL);
	rtn->number = content;
	rtn->position = 0;
	rtn->next = NULL;
	insert_pos(stack_a, rtn);
	return (rtn);
}
