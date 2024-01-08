#include "push_swap.h"
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current_node;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current_node = *lst;
	while (current_node->next)
	{
		current_node = current_node->next;
	}
	current_node->next = new;
}
