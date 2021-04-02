#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>


t_list	*ft_create_elem(void *data)
{
	t_list *ret;

	ret = (t_list *)malloc(sizeof(t_list));

	ret->data = data;
	ret->next = NULL;
	return (ret);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *new_node;
	t_list *idx;

	new_node = ft_create_elem(data);
	if (*begin_list == NULL)
	{
		*begin_list = new_node;
		return ;
	}
	idx = *begin_list;
	while (idx->next)
	{
		idx = idx->next;
	}
	idx->next = new_node;
}

void	ft_list_reverse_fun(t_list *begin_list);


int		main(void)
{
	int		index;
	int		*malloced_index;
	//int		*data;
	t_list	*list;
	t_list	*current;

	index = 1;
	list = ft_create_elem(0);
	while (index < 10)
	{
		malloced_index = malloc(sizeof(int));
		*malloced_index = index;
		ft_list_push_back(&list, (void *)malloced_index);
		printf("%p list[%d] = %d\n", malloced_index, index, *malloced_index);
		index++;
	}
	index = 1;
	ft_list_reverse_fun(list->next);
	printf("Reversed\n");
	current = list->next;
	while (index < 10)
	{
		//data = (int *)current->data;
		//printf("list[%d] = %d\n", index, data != 0 ? *data : -1);
		printf("list[%d] = %d\n", index, *((int *)current->data));
		index++;
		current = current->next;
	}
}