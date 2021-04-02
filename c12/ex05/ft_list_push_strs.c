/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanlee <chanlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:27:34 by chanlee           #+#    #+#             */
/*   Updated: 2021/04/02 02:28:27 by chanlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*firstnode;
	t_list	*node;
	int		i;

	firstnode = (NULL);
	i = 0;
	while (i < size)
	{
		node = ft_create_elem((void *)strs[i]);
		node->next = firstnode;
		firstnode = node;
	}
	return (firstnode);
}
