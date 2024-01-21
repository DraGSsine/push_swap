/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:40:41 by youchen           #+#    #+#             */
/*   Updated: 2024/01/21 22:12:44 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <limits.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdio.h>
#define malloc(x) NULL
void	check_dublicat(t_list **stack_a);
char	*get_next_line(int fd);
char	**parse(int ac, char **av);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content, t_list *stack);
int		ft_atoi(const char *nptr);
int		ft_lstsize(t_list *lst);
int		sorted(t_list *stack);
void	free_list(t_list *list);
int		ft_strcmp(const char *s1, const char *s2);
void	swap_stack(t_list **stack);
void	push_stack(t_list **from, t_list **to);
void	rotate_stack(t_list **stack);
void	reverse_rotate_stack(t_list **stack);
void	swap_tow(t_list **stack_a, t_list **stack_b);
void	rotate_tow(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_tow(t_list **stack_a, t_list **stack_b);
#endif
