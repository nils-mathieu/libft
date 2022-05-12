/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:09:57 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/12 22:58:23 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rdresult	ft_read_count(t_reader *r, char c, size_t *count)
{
	t_rdresult	res;
	uint8_t		byte;

	*count = 0;
	while (1)
	{
		res = ft_read_byte(r, &byte);
		if (res == FT_RDRSLT_READ_ERROR)
			return (FT_RDRSLT_READ_ERROR);
		if (res == FT_RDRSLT_DONE)
			return (FT_RDRSLT_CONTINUE);
	}
	return (FT_RDRSLT_CONTINUE);
}
