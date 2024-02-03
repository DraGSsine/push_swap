/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:40:41 by youchen           #+#    #+#             */
/*   Updated: 2024/01/29 12:18:54 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				number;
	size_t			position;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	char	*ptr_str;
	size_t	i;
	size_t	x;
	size_t	s1_len;
	size_t	s2_len;
}	t_data;

char	*ft_strjoin_bonus(char *s1, char *buff);
char	*ft_strjoin(char *s1, char *buff);
void	ft_error(void);
int		ft_atoi(const char *nptr);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content, t_list *stack);
int		ft_lstsize(t_list *lst);
char	**ft_split(const char *s, char c);
int		ft_strlen(const char *s);
void	check_dublicat(t_list **stack_a);
char	*get_next_line(int fd);
char	**pars(int ac, char **av);
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
