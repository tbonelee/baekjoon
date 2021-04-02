/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanlee <chanlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:21:50 by chanlee           #+#    #+#             */
/*   Updated: 2021/04/02 02:23:16 by chanlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap(t_list *before, t_list *a, t_list *b)
{
	t_list *temp;

	temp = b->next;
	b->next = a;
	a->next = temp;
	if (before != NULL)
		before->next = b;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*j;
	void	*temp;
	int		flag;

	if (*begin_list == NULL)
		return ;
	flag = 1;
	while (flag)
	{
		flag = 0;
		j = *begin_list;
		while (j->next)
		{
			if ((*cmp)(j->data, j->next->data) > 0)
			{
				temp = j->data;
				j->data = j->next->data;
				j->next->data = temp;
				flag = 1;
			}
			j = j->next;
		}
	}
}
