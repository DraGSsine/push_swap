/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:25:55 by youchen           #+#    #+#             */
/*   Updated: 2024/01/22 07:43:33 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	int				number;
	size_t			position;
	struct s_list	*next;
}	t_list;
typedef struct s_node_found_at
{
	size_t	iter;
	t_list	*location;
}	t_node_at;

typedef struct s_stacks
{
	size_t	list_size;
	t_list	*stack_a;
	t_list	*stack_b;
	char	**numbers;
}	t_stacks;

typedef struct s_data
{
	char	*ptr_str;
	size_t	i;
	size_t	x;
	size_t	s1_len;
	size_t	s2_len;
}	t_data;
void		take_node_to_toop(t_list **stack_b, t_node_at node,
				char *rrr, char *rr);
t_node_at	found_node_at(t_list **stack, size_t position_to_found);
void		ft_free(char **s);
void		check_dublicat(t_list **stack_a);
void		push_back_to_a(t_list **stack_a, t_list **stack_b);
void		sort_large_numbers(t_list **stack_a,
				t_list **stack_b, size_t list_size);
void		sort(t_list **stack_a, t_list **stack_b, size_t list_size);
int			is_still_chunk_values(t_list *stack, size_t chunk_values);
void		free_list(t_list *list);
int			sorted(t_list *stack);
void		sort_five_numbers(t_list **stack_a, t_list **stack_b);
void		swap_stack(t_list **stack, char *instraction);
void		push_stack(t_list **from, t_list **to, char *instraction);
void		rotate_stack(t_list **stack, char *instraction);
void		reverse_rotate_stack(t_list **stack, char *instraction);
void		stort_three_numbers(t_list **stack);
void		sort_four_numbers(t_list **stack_a, t_list **stack_b);
char		**pars(int ac, char **av);
char		*ft_strjoin(char *s1, char *buff);
void		ft_error(void);
int			ft_atoi(const char *nptr);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstnew(int content, t_list *stack);
int			ft_lstsize(t_list *lst);
char		**ft_split(const char *s, char c);
int			ft_strlen(const char *s);
void		free_list(t_list *list);
void		take_chunk_to_top(t_list **stack_a, size_t chunk);
#endif
