/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:10:54 by youchen           #+#    #+#             */
/*   Updated: 2024/01/20 11:45:27 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	take_node_to_toop(t_list **stack_b, t_node_found_at node)
{
	while (node.location && (*stack_b)->position != node.location->position)
	{
		if (node.iter < (size_t)(ft_lstsize(*stack_b) / 2))
			rotate_stack(stack_b, "rb");
		else
			reverse_rotate_stack(stack_b, "rrb");
	}
}

t_node_found_at	node_at(t_list **stack, size_t position_to_found)
{
	t_list			*current;
	size_t			i;
	t_node_found_at	node;

	i = 0;
	current = *stack;
	while (current && (current->position != position_to_found))
	{
		i++;
		current = current->next;
	}
	node.iter = i;
	node.location = current;
	return (node);
}

int	check(size_t second_large, size_t large, size_t size_of_list)
{
	size_t	number_of_instraction_1;
	size_t	number_of_instraction_2;

	if (second_large <= (size_of_list / 2))
		number_of_instraction_2 = second_large;
	else
		number_of_instraction_2 = size_of_list - second_large + 1;
	if (large <= (size_of_list / 2))
		number_of_instraction_1 = large;
	else
		number_of_instraction_1 = size_of_list - large + 1;
	if (number_of_instraction_1 > number_of_instraction_2)
		return (1);
	return (0);
}

void	push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	size_t			large_number;
	t_node_found_at	large_node;
	t_node_found_at	second_large_node;

	while (*stack_b)
	{
		large_number = ft_lstsize(*stack_b) - 1;
		large_node = node_at(stack_b, large_number);
		second_large_node = node_at(stack_b, large_number - 1);
		if (check(second_large_node.iter,
				large_node.iter, ft_lstsize(*stack_b)))
		{
			take_node_to_toop(stack_b, second_large_node);
			push_stack(stack_b, stack_a, "pa");
			take_node_to_toop(stack_b, large_node);
			push_stack(stack_b, stack_a, "pa");
			swap_stack(stack_a, "sa");
		}
		else
		{
			take_node_to_toop(stack_b, large_node);
			push_stack(stack_b, stack_a, "pa");
		}
	}
}

int	main(int argc, char **argv)
{
	int		i;
	size_t	list_size;
	t_list	*stack_a;
	t_list	*stack_b;
	char	**numbers;

	i = 0;
	numbers = parse(argc, argv);
	if (!numbers)
		return (1);
	while (numbers[i])
		ft_lstadd_back(&stack_a,
			ft_lstnew(ft_atoi(numbers[i++]), stack_a));
	ft_free(numbers);
	check_dublicat(&stack_a);
	list_size = ft_lstsize(stack_a);
	if (sorted(stack_a))
		return (1);
	sort(&stack_a, &stack_b, list_size);
	return (free_list(stack_a), free_list(stack_b), 0);
}
