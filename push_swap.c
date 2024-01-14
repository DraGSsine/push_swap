/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:10:54 by youchen           #+#    #+#             */
/*   Updated: 2024/01/14 19:13:02 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_list *stack)
{
	t_list *current = stack;

	while (current)
	{
		printf("%d\n", current->number);
		current = current->next;
	}
}

void sort_large_numbers(t_list **stack_a, t_list **stack_b)
{
	size_t list_size;
	size_t chunks_step;
	size_t half_chunk;
	t_list *current;

	current = *stack_a;
	list_size = ft_lstsize(*stack_a);
	chunks_step = list_size / 5;
	half_chunk = chunks_step / 2;
	if (list_size > 5 && list_size <= 100)
	{
		while (current && current->position > chunks_step)
		{
			current = current->next;
			rotate_a(stack_a);
		}
		current = *stack_a;
		while (stack_a && (*stack_a)->position <= chunks_step)
		{
			push_b(stack_a, stack_b);
			if ((*stack_b)->position > half_chunk)
				rotate_a(stack_b);
		}
	}
}

int	main(int argc, char **argv)
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
	if (sorted(stack_a))
		return (1);
	if (list_size == 2)
		swap_a(&stack_a);
	else if (list_size == 3)
		stort_three_numbers(&stack_a);
	else if (list_size == 4)
		sort_four_numbers(&stack_a, &stack_b);
	else if (list_size == 5)
		sort_five_numbers(&stack_a, &stack_b);
	else
		sort_large_numbers(&stack_a, &stack_b);
	printf("--------Stack A--------\n");
	print_list(stack_a);
	printf("--------Stack B--------\n");
	print_list(stack_b);
	return (0);
}
