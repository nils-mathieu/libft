/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_byte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:22:01 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/12 01:49:00 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rdresult	__ft_reader_refill(t_reader *r);

t_rdresult	ft_read_byte(t_reader *r, uint8_t *byte)
{
	t_rdresult	res;

	if (r->cur == r->buf.init)
	{
		res = __ft_reader_refill(r);
		if (res == FT_RDRSLT_READ_ERROR || res == FT_RDRSLT_DONE)
			return (res);
	}
	*byte = ((uint8_t *)r->buf.data)[r->cur];
	r->cur++;
	return (FT_RDRSLT_CONTINUE);
}
