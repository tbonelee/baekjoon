/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanlee <chanlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:29:52 by chanlee           #+#    #+#             */
/*   Updated: 2021/04/02 02:29:53 by chanlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int ret;

	ret = 0;
	while (begin_list != NULL)
	{
		ret++;
		begin_list = begin_list->next;
	}
	return (ret);
}
