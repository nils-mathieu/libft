/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_byte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:22:01 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/13 15:13:08 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rdres	__ft_reader_refill(t_reader *r);

t_rdres	ft_read_byte(t_reader *r, uint8_t *byte)
{
	t_rdres	res;

	if (r->cur == r->buf.init)
	{
		res = __ft_reader_refill(r);
		if (res == FT_RDRES_READ_ERROR || res == FT_RDRES_DONE)
			return (res);
	}
	*byte = ((uint8_t *)r->buf.data)[r->cur];
	r->cur++;
	return (FT_RDRES_CONTINUE);
}
