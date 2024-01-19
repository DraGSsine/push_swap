/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:47:59 by youchen           #+#    #+#             */
/*   Updated: 2024/01/19 11:52:16 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	insert_pos(t_list *stack, t_list *rtn)
{
	while (stack && rtn)
	{
		if (rtn->number > stack->number)
			(rtn->position)++;
		else
			stack->position++;
		stack = stack->next;
	}
}

t_list	*ft_lstnew(int content, t_list *stack)
{
	t_list	*rtn;

	rtn = malloc(sizeof(t_list));
	if (!rtn)
		return (NULL);
	rtn->number = content;
	rtn->position = 0;
	rtn->next = NULL;
	insert_pos(stack, rtn);
	return (rtn);
}
