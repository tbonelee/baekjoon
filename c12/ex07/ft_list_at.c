/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanlee <chanlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:26:38 by chanlee           #+#    #+#             */
/*   Updated: 2021/04/02 02:26:39 by chanlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list *ret;

	ret = begin_list;
	while (nbr)
	{
		if (ret == NULL)
			return (NULL);
		ret = ret->next;
		nbr--;
	}
	return (ret);
}
