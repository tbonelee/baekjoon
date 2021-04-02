/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanlee <chanlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:26:24 by chanlee           #+#    #+#             */
/*   Updated: 2021/04/02 02:26:25 by chanlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *temp1;
	t_list *temp2;

	if (*begin_list == NULL)
		return ;
	temp1 = 0;
	while (*begin_list)
	{
		temp2 = (*begin_list)->next;
		(*begin_list)->next = temp1;
		(*begin_list) = temp2;
		temp1 = temp1->next;
	}
	*begin_list = temp1;
}
