/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanlee <chanlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:28:47 by chanlee           #+#    #+#             */
/*   Updated: 2021/04/02 02:28:57 by chanlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_node;
	t_list	*idx;

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
