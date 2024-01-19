/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_instractions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:40:45 by youchen           #+#    #+#             */
/*   Updated: 2024/01/19 18:44:31 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_tow(t_list **stack_a, t_list **stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
}

void	rotate_tow(t_list **stack_a, t_list **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
}

void	reverse_rotate_tow(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_stack(stack_b);
	reverse_rotate_stack(stack_a);
}
