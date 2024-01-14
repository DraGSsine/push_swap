/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:25:55 by youchen           #+#    #+#             */
/*   Updated: 2024/01/14 14:04:14 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int		number;
	size_t	position;
	struct	s_list *next;
}	t_list;

void	print_list(t_list *stack);

void	ft_lstcat(t_list **first_list, t_list **second_list);
void	sort_five_numbers(t_list **stack_a, t_list **stack_b);
int		sorted(t_list *stack);
t_list	*ft_lstnew(int content, t_list *stack);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	swap_a(t_list **list);
void	push_b(t_list **stack_a, t_list **stack_b);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	rotate_a(t_list **stack);
void	reverse_rotate_a(t_list **stack);
void	stort_three_numbers(t_list **stack);
void	sort_four_numbers(t_list **stack_a, t_list **stack_b);
#endif
