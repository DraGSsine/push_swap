/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:44:46 by youchen           #+#    #+#             */
/*   Updated: 2024/01/13 11:59:32 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstcat(t_list **first_list, t_list **second_list)
{
	t_list	*current;

	current = *second_list;
	while (current->next)
		current = current->next;
	current->next = *first_list;
	*first_list = *second_list;
}
