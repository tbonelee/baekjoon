/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanlee <chanlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:23:25 by chanlee           #+#    #+#             */
/*   Updated: 2021/04/02 02:24:16 by chanlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *temp;

	temp = *begin_list1;
	if (temp == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = begin_list2;
}
