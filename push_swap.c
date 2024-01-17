/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:10:54 by youchen           #+#    #+#             */
/*   Updated: 2024/01/17 11:33:15 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef	struct	s_node_found_at
{
	size_t	iter;
	t_list	*location;
}	t_node_found_at;

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void print_list(t_list *stack)
{
	t_list *current = stack;

	while (current)
	{
		printf("%d\n", current->number);
		current = current->next;
	}
}

void	take_node_to_toop (t_list **stack_b, t_node_found_at node)
{
	while ((*stack_b)->position != node.location->position)
	{
		if (node.iter <= (size_t)(ft_lstsize(*stack_b) / 2))
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
		if (second_large_node.iter < large_node.iter)
		{
			take_node_to_toop(stack_b, second_large_node);
			push_stack(stack_b, stack_a, "pa");
			take_node_to_toop(stack_b, large_node);
			push_stack(stack_b, stack_a, "pa");
		}
		else
		{
			take_node_to_toop(stack_b, large_node);
			push_stack(stack_b, stack_a, "pa");
		}
	}
}
void sort_large_numbers(t_list **stack_a, t_list **stack_b)
{
	size_t chunk;
	size_t chunks_step;

	chunk = ft_lstsize(*stack_a) / 10;
	chunks_step = ft_lstsize(*stack_a) / 10;
	while ((*stack_a))
	{
		while ((*stack_a)->position >= chunk)
			rotate_stack(stack_a, "ra");
		while ((*stack_a) && (*stack_a)->position < chunk)
		{
			if ((*stack_a)->position < chunk - (chunks_step / 2))
				push_stack(stack_a, stack_b, "pb");
			else
			{
				push_stack(stack_a, stack_b, "pb");
				rotate_stack(stack_b, "rb");
			}
		}
		chunk += chunks_step;
	}
}

int main(int argc, char **argv)
{
	int i;
	size_t list_size;
	t_list *stack_a = NULL;
	t_list *stack_b = NULL;

	i = 1;
	(void)argc;
	while (argv[i])
		ft_lstadd_back(&stack_a, ft_lstnew(atoi(argv[i++]), stack_a));
	list_size = ft_lstsize(stack_a);
	// printf("--------Stack A--------\n");
	// print_list(stack_a);
	if (sorted(stack_a))
		return (1);
	if (list_size == 2)
		swap_stack(&stack_a, "sa");
	else if (list_size == 3)
		stort_three_numbers(&stack_a);
	else if (list_size == 4)
		sort_four_numbers(&stack_a, &stack_b);
	else if (list_size == 5)
		sort_five_numbers(&stack_a, &stack_b);
	else
		sort_large_numbers(&stack_a, &stack_b);
	// printf("--------Stack B Beffore--------\n");
	// print_list(stack_b);

	push_back_to_a(&stack_a, &stack_b);
	// printf("--------Stack B--------\n");
	// print_list(stack_b);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
