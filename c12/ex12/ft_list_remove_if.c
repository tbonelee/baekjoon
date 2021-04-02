/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanlee <chanlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:24:34 by chanlee           #+#    #+#             */
/*   Updated: 2021/04/02 02:25:04 by chanlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
void (*free_fct)(void *))
{
	t_list *idx;
	t_list *before;
	t_list *temp;

	idx = *begin_list;
	before == NULL;
	while (idx)
	{
		if ((*cmp)(idx->data, data_ref) == 0)
		{
			temp = idx;
			if (before != NULL)
				before->next = idx->next;
			if (idx == *begin_list)
				*begin_list = idx->next;
			idx = idx->next;
			(*free_fct)(temp->data);
			free(temp);
		}
		else
		{
			before = idx;
			idx = idx->next;
		}
	}
}
