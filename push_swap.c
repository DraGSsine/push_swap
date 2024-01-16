/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:10:54 by youchen           #+#    #+#             */
/*   Updated: 2024/01/16 13:42:02 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *list)
{
	t_list *tmp;

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

void push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	size_t size_of_b;
	size_t largest_number;
	size_t second_largest_number;
	t_list *current;
	size_t i;

	i = 0;
	size_of_b = ft_lstsize(*stack_b);
	largest_number = size_of_b - 1;
	second_largest_number = size_of_b - 2;
	current = *stack_b;

	while (current)
	{
		if (current->position == largest_number)
		{
			while ((*stack_b) && (*stack_b)->position != largest_number)
			{
				if (i < (size_of_b / 2))
					rotate_stack(stack_b, "rb");
				else
					reverse_rotate_stack(stack_b, "rrb");
			}
			push_stack(stack_b, stack_a, "sa");
		}
		i++;
		current = current->next;
	}
}

void ¸sort_large_numbers(t_list **stack_a, t_list **stack_b)
{
	size_t list_size;
	size_t chunks_step;
	size_t half_chunk;
	t_list *current;
	size_t i;
	size_t chunk;

	list_size = ft_lstsize(*stack_a);
	current = *stack_a;
	chunk = list_size / 5;
	chunks_step = list_size / 5;
	if (list_size > 5 && list_size <= 100)
	{
		while (*stack_a)
		{
			list_size = ft_lstsize(*stack_a);
			half_chunk = chunks_step / 2;
			i = 0;
			while (*stack_a && i < list_size)
			{
				if ((*stack_a)->position >= chunks_step)
					rotate_stack(stack_a, "ra");
				else
				{
					push_stack(stack_a, stack_b, "pb");
					if ((*stack_b)->position >= half_chunk)
						rotate_stack(stack_b, "rb");
				}
				i++;
			}
			chunks_step += chunk;
		}
	}
}

void checkLeaks() {
    system("leaks push_swap");
}

int main(int argc, char **argv)
{
	int i;
	size_t list_size;
	t_list *stack_a = NULL;
	t_list *stack_b = NULL;

    atexit(checkLeaks);
	i = 1;
	(void)argc;
	while (argv[i])
		ft_lstadd_back(&stack_a, ft_lstnew(atoi(argv[i++]), stack_a));
	list_size = ft_lstsize(stack_a);
	if (sorted(stack_a))
		return (1);
	printf("--------Stack A Beffore--------\n");
	print_list(stack_a);
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
	printf("--------Stack B Beffore--------\n");
	print_list(stack_b);
	while (stack_b)
		push_back_to_a(&stack_a, &stack_b);
	// printf("--------Stack A--------\n");
	// print_list(stack_a);
	// printf("--------Stack B--------\n");
	// print_list(stack_b);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
