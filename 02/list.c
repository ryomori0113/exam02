#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	if(begin_list == 0)
		return (0);
	else
		return(1 + ft_list_size(begin_list->next));
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while(begin_list)
	{
		(*f)(begin_list(begin_list->data))
		begin_list = begin_list->next;
	}
}

#include <stdlib.h>
#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int swap;
	t_list *tmp;

	tmp = lst;
	while(lst->next != NULL)
	{
		swap = lst->data;
		lst->data = lst->next->data;
		lst->next->data = swap;
		lst = tmp;
	}
	else
	{
		lst= lst->next;
	}
	lst = tmp;
	return (lst);
}