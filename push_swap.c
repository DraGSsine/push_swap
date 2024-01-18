/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:10:54 by youchen           #+#    #+#             */
/*   Updated: 2024/01/18 14:33:26 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *stack)
{
	if (!stack)
		return ;
	printf("%i (%zu)\n",stack->number, stack->position);
	print_list(stack->next);
}

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

void	sort_large_numbers(t_list **stack_a, t_list **stack_b, size_t list_size)
{
	size_t	chunk;
	size_t	div;

	div = 5;
	if (list_size > 200)
		div = 10;
	chunk = list_size / div;
	while ((*stack_a))
	{
		while ((*stack_a)->position >= chunk)
			rotate_stack(stack_a, "ra");
		while ((*stack_a) && (*stack_a)->position < chunk)
		{
			if ((*stack_a)->position < chunk - ((list_size / div) / 2))
				push_stack(stack_a, stack_b, "pb");
			else
			{
				push_stack(stack_a, stack_b, "pb");
				rotate_stack(stack_b, "rb");
			}
		}
		if (!is_still_chunk_values(*stack_a, chunk))
			chunk += (list_size / div);
	}
}
// char **pars(int ac, char **av)
// {
// 	if (ac  < 3)
// 		exit(1);

// }

int	main(int argc, char **argv)
{
	int			i;
	t_stacks	stacks;
	char		**numbers;

	i = 1;
	numbers = pars(argc, argv);
	(void)argc;
	while (argv[i])
		ft_lstadd_back(&stacks.stack_a, ft_lstnew(atoi(numbers[i++]), stacks.stack_a));
	stacks.list_size = ft_lstsize(stacks.stack_a);
	if (sorted(stacks.stack_a))
		return (1);
	if (stacks.list_size == 2)
		swap_stack(&stacks.stack_a, "sa");
	else if (stacks.list_size == 3)
		stort_three_numbers(&stacks.stack_a);
	else if (stacks.list_size == 4)
		sort_four_numbers(&stacks.stack_a, &stacks.stack_b);
	else if (stacks.list_size == 5)
		sort_five_numbers(&stacks.stack_a, &stacks.stack_b);
	else
	{
		sort_large_numbers(&stacks.stack_a, &stacks.stack_b, stacks.list_size);
		push_back_to_a(&stacks.stack_a, &stacks.stack_b);
	}
	return (free_list(stacks.stack_a), free_list(stacks.stack_b), 0);
}
