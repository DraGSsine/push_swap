/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:04:14 by youchen           #+#    #+#             */
/*   Updated: 2024/01/18 14:04:26 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign *= -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + nptr[i++] - '0';
	return (result * sign);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current_node;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current_node = *lst;
	while (current_node->next)
	{
		current_node = current_node->next;
	}
	current_node->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

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
