/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_str_uint32.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:27:12 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/13 15:11:56 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rdres	ft_read_str_uint32(t_reader *r, uint32_t *result)
{
	uint8_t		byte;
	t_rdres	res;

	res = ft_read_byte(r, &byte);
	if (res == FT_RDRES_READ_ERROR || res == FT_RDRES_DONE)
		return (res);
	if (byte < '0' || '9' < byte)
		return (r->cur--, FT_RDRES_PARSE_ERROR);
	*result = 0;
	while (true)
	{
		res = ft_read_byte(r, &byte);
		if (res == FT_RDRES_READ_ERROR)
			return (FT_RDRES_READ_ERROR);
		if (res == FT_RDRES_DONE)
			return (FT_RDRES_CONTINUE);
		if (byte < '0' || '9' < byte)
			return (r->cur--, FT_RDRES_CONTINUE);
		if (*result > UINT32_MAX / 10)
			return (FT_RDRES_PARSE_ERROR);
		*result *= 10;
		if (*result > UINT32_MAX - (byte - '0'))
			return (FT_RDRES_PARSE_ERROR);
		*result += byte - '0';
	}
}
