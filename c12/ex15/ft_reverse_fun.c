/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_fun.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanlee <chanlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:20:11 by chanlee           #+#    #+#             */
/*   Updated: 2021/04/02 02:20:42 by chanlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_swap(void **a, void **b)
{
	void *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*j;
	int		count;
	int		flag;
	int		idx;
	int		cycle;

	if (begin_list == NULL || begin_list->next == NULL)
		return ;
	count = 0;
	cycle = -1;
	flag = 1;
	while (flag || count - ++cycle != 0)
	{
		idx = 0;
		j = begin_list;
		while (j->next && (cycle == 0 || (cycle != 0 && idx != count - cycle)))
		{
			idx++;
			ft_swap(&(j->data), &(j->next->data));
			j = j->next;
			if (flag == 1)
				count++;
		}
		flag = 0;
	}
}
