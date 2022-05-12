/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_str_uint32.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:27:12 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/12 10:59:31 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

sta

t_rdresult	ft_read_str_uint32(t_reader *r, uint32_t *result)
{
	uint8_t		byte;
	t_rdresult	res;

	res = ft_read_byte(r, &byte);
	if (res == FT_RDRSLT_READ_ERROR || res == FT_RDRSLT_DONE)
		return (res);
	if (byte < '0' || '9' < byte)
		return (r->cur--, FT_RDRSLT_PARSE_ERROR);
	*result = 0;
	while (true)
	{
		res = ft_read_byte(r, &byte);
		if (res == FT_RDRSLT_READ_ERROR)
			return (FT_RDRSLT_READ_ERROR);
		if (res == FT_RDRSLT_DONE)
			return (FT_RDRSLT_CONTINUE);
		if (byte < '0' || '9' < byte)
			return (r->cur--, FT_RDRSLT_CONTINUE);
		if (*result > UINT32_MAX / 10)
			return (FT_RDRSLT_PARSE_ERROR);
		*result *= 10;
		if (*result > UINT32_MAX - (byte - '0'))
			return (FT_RDRSLT_PARSE_ERROR);
		*result += byte - '0';
	}
}
