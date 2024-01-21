/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:11:19 by youchen           #+#    #+#             */
/*   Updated: 2024/01/21 16:42:51 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ifaat(t_list **stack_a, t_list **stack_b, char *instraction)
{
	if (ft_strcmp(instraction, "sa\n"))
		swap_stack(stack_a);
	else if (ft_strcmp(instraction, "sb\n"))
		swap_stack(stack_b);
	else if (ft_strcmp(instraction, "pa\n"))
		push_stack(stack_b, stack_a);
	else if (ft_strcmp(instraction, "pb\n"))
		push_stack(stack_a, stack_b);
	else if (ft_strcmp(instraction, "ra\n"))
		rotate_stack(stack_a);
	else if (ft_strcmp(instraction, "rb\n"))
		rotate_stack(stack_b);
	else if (ft_strcmp(instraction, "rra\n"))
		reverse_rotate_stack(stack_a);
	else if (ft_strcmp(instraction, "rrb\n"))
		reverse_rotate_stack(stack_b);
	else if (ft_strcmp(instraction, "ss\n"))
		swap_tow(stack_a, stack_b);
	else if (ft_strcmp(instraction, "rr\n"))
		rotate_tow(stack_a, stack_b);
	else if (ft_strcmp(instraction, "rrr\n"))
		reverse_rotate_tow(stack_a, stack_b);
	else
		ft_error();
}

void	read_instractions(t_list **stack_a, t_list **stack_b)
{
	char	*instraction;

	instraction = get_next_line(1);
	while (instraction)
	{
		ifaat(stack_a, stack_b, instraction);
		free(instraction);
		instraction = get_next_line(1);
	}
	free(instraction);
}

int	main(int argc, char **argv)
{
	int		i;
	size_t	list_size;
	t_list	*stack_a;
	t_list	*stack_b;
	char	**numbers;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	numbers = parse(argc, argv);
	if (!numbers)
		return (1);
	while (numbers[i])
		ft_lstadd_back(&stack_a,
			ft_lstnew(ft_atoi(numbers[i++]), stack_a));
	list_size = ft_lstsize(stack_a);
	if (sorted(stack_a))
		return (write(1, "OK", 2), 0);
	check_dublicat(&stack_a);
	read_instractions(&stack_a, &stack_b);
	if (sorted(stack_a) && !(stack_b))
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
	return (free_list(stack_a), free_list(stack_b), 0);
}
