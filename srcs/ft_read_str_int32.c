/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_str_int32.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:49:08 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/13 15:11:08 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rdres	ft_read_int32(t_reader *r, int32_t *result)
{
	uint8_t	byte;
	t_rdres	res;
	bool	neg;

	res = ft_read_byte(r, &byte);
	if (res == FT_RDRES_READ_ERROR || res == FT_RDRES_DONE)
		return (res);
	neg = false;
	if (byte == '-')
		neg = true;
	else if (byte == '+')
		;
	else
		r->cur--;
	res = ft_read_str_uint32(r, (uint32_t *)result);
	if (res == FT_RDRES_READ_ERROR || res == FT_RDRES_PARSE_ERROR)
		return (res);
	else if (res == FT_RDRES_DONE)
		*result = 0;
	if (*result < 0)
		return (FT_RDRES_PARSE_ERROR);
	if (neg)
		*result = -*result;
	return (FT_RDRES_CONTINUE);
}
