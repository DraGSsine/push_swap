/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:45:25 by youchen           #+#    #+#             */
/*   Updated: 2024/01/21 07:43:18 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				number;
	size_t			position;
	struct s_list	*next;
}	t_list;

void	ft_error(void);
int		ft_atoi(const char *nptr);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content, t_list *stack);
int		ft_lstsize(t_list *lst);
char	**ft_split(const char *s, char c);
int		ft_strlen(const char *s);
#endif
