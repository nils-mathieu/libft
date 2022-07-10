/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader_reserve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:31:58 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 16:51:21 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_mem_move_left(uint8_t *dst, const uint8_t *src, size_t count)
{
	while (count)
	{
		*dst = *src;
		src++;
		dst++;
		count--;
	}
}

static void	reallocate(t_reader *r, size_t new_cap)
{
	uint8_t	*new_data;

	new_data = ft_alloc(new_cap);
	if (r->cap)
	{
		ft_mem_copy(new_data, r->data + r->con, r->init - r->con);
		free(r->data);
	}
	r->data = new_data;
	r->cap = new_cap;
	r->init -= r->con;
	r->con = 0;
}

void	ft_reader_reserve(t_reader *r, size_t count)
{
	if (r->cap - r->init >= count)
		return ;
	if (r->cap - r->init + r->con >= count)
	{
		ft_mem_move_left(r->data, r->data + r->con, r->con);
		r->init -= r->con;
		r->con = 0;
		return ;
	}
	reallocate(r, count - (r->cap - r->init + r->con));
}
